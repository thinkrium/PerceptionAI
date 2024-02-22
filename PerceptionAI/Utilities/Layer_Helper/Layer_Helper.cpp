 //
// Created by thome on 1/13/2024.
//


#include "Layer_Helper.h"


namespace Perception {
    namespace Network {
        namespace Utilities {


            /**l
             * Passes the layers outputs forward
             * @param layer
             * @return
             */
            Perception_Element_Vector<Node> Layer_Helper::Propagate_Forward(Layer layer) {
                return layer.getOutputNodes();
            }

            Perception_Element_Vector<Node> Layer_Helper::Propagate_Backward(Layer layer) {
                return layer.getOutputNodes();
            }

            Node Layer_Helper::Activate_Node_With_ReLU(Node node) {
                try {
                    if(!node.isValueIsSet()) {throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Value_Set);}
                    if (node.getValue() <= 0) {
                        node.setActivatedValue(0);
                    }
                    else {
                        node.setActivatedValue(node.getValue());
                    }
                }
                catch (exception e) {
                    node.setHealthStatus(Perception_Enumerations::healthStatus::error);
                    node.addErrorMessage(e.what());
                }

                return node;
            }

            /// <summary>
            /// activation with softmax is dependent on an exponential sum
            /// </summary>
            /// <param name="layer"></param>
            double Layer_Helper::Sum_The_Layers_Nodes_Exponential_Values(Layer &layer) {


                double layersExponentialSum = 0;

                try {
                    if(
                            layer.getHealthStatus() == Perception_Enumerations::healthStatus::error
                            ||
                            layer.getLocalNodes().getHealthStatus() == Perception_Enumerations::healthStatus::error
                            ) {
                        layer.addErrorMessage(Perception_Enumerations::errorMessages::Layer_Helper_Attempted_Activation_But_Failed);
                    }
                    Perception_Element_Vector<Node> localNodes = layer.getLocalNodes();

                    for (int nodeIndex = 0; nodeIndex < layer.getNodeCountPerLayer(); nodeIndex++) {
                        layersExponentialSum += exp(localNodes.getElementAt(nodeIndex).getValue());
                    }

                }
                catch (exception e) {
                    layer.setHealthStatus(Perception_Enumerations::healthStatus::error);
                    layer.addErrorMessage(e.what());
                }

                return layersExponentialSum;


            }

            Node Layer_Helper::Activate_Node_With_Softmax(Node node, double layersExponentialSum) {
                try {
                    if(!node.isValueIsSet()) {throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Value_Set);}
                    node.setActivatedValue(
                            exp(node.getValue()) / layersExponentialSum
                    );
                }
                catch (exception e) {
                    node.setHealthStatus(Perception_Enumerations::healthStatus::error);
                    node.addErrorMessage(e.what());
                }

                return node;
            }

            void Layer_Helper::Calculate_Loss_With_Categorical_Cross_Entropy() {

            }

            Node Layer_Helper::Calculate_Nodes_Derivative_Of_ReLu(Node node) {

                try {
                    if (!node.checkIsActivatedValueSet() ) throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set);
                    node.setDerivedValue(  (node.getActivatedValue() > 0) ? 1 : 0 );
                }
                catch (exception e) {
                    node.setHealthStatus(Perception_Enumerations::healthStatus::error);
                    node.addErrorMessage(e.what());
                }

                return node;
            }

            //TODO: figure out what you want to do here
            Node Layer_Helper::Calculate_Derivative_Of_Softmax(Node node, Layer layer, Result result) {

                float derived_activation = 0;
                float numerator_summation = 0;
                float denominator_summation = 0;

                int target_index = result.getIndexOfOneHotEncodedTargetSetToTrue();

                // node output target * (for all node output except target sumed) / all node outputs summed

                Perception_Element_Vector<Node> elementVector = layer.getLocalNodes();

                int nodeIndex = 0;

                for (const auto &item: elementVector.getElementVector()) {
                    if (nodeIndex != target_index) {

                        numerator_summation += ((Node) item).getValue();
                    }
                    denominator_summation += ((Node) item).getValue();
                }

                derived_activation = node.getValue() * numerator_summation / denominator_summation;

                node.setDerivedValue(derived_activation);

                return node;
            }

            //TODO: figure out what you want to do here
            Node Layer_Helper::Calculate_Categorical_Cross_Entropy_Derivative_of_Node(Node node) {

//                float activated_value = node.getActivatedValue();
//                float loss_derivative =  1 / activated_value;
//                results.Add_Loss_Derivative_To_Loss_Derivatives(loss_derivative);
            }

            Node Layer_Helper::Calculate_Cross_Entropy_With_Softmax_Derivative_Of_Node(Node node) {
//                let correct_target_index = results.Get_Index_Of_One_Hot_Encoded_Target_Set_To_True();
//                // does this need to be based off of activatived value or dot product
//                let derived_activation_value = (node_index == correct_target_index) ? node.Get_Activated_Value() - 1 : node.Get_Activated_Value();
//                node.Set_Derived_Activation_Value(derived_activation_value);


            }

            Layer_Helper::Layer_Helper() {
                this->setPerceptionMaths(Perception_Maths());
            }

            Layer_Helper::~Layer_Helper() {

            }

            void Layer_Helper::Activate_Nodes_With(Layer &layer,
                                                   Perception_Enumerations::activationMethod activationMethod) {

                try {
                    if(layer.getHealthStatus() == Perception_Enumerations::healthStatus::error) {
                        throw runtime_error(Perception_Enumerations::errorMessages::General_Error);
                    }

                    switch (activationMethod) {
                        case Perception_Enumerations::activationMethod::ReLU :
                            this->Activate_Nodes_With_ReLU(layer);
                            break;
                        case Perception_Enumerations::activationMethod::Softmax :
                            this->Activate_Nodes_With_Softmax(layer );
                            break;
                        default :
                            throw runtime_error(
                                    Perception_Enumerations::errorMessages::Layer_Helper_Attempted_Activation_But_Failed);
                    }
                }
                catch (exception e) {
                    layer.setHealthStatus(Perception_Enumerations::healthStatus::error);
                    layer.addErrorMessage(e.what());
                }
            }

            void Layer_Helper::Prepare_Forward_Propagation_Without_Activating(Layer &previousLayer, Layer &currentLayer) {

                try {

                    if(
                        !(
                            previousLayer.getOutputNodes().getHealthStatus() == Perception_Enumerations::healthStatus::ok
                            &&
                            currentLayer.getWeights().getHealthStatus() == Perception_Enumerations::healthStatus::ok
                        )
                    ) {
                        throw runtime_error(Perception_Enumerations::errorMessages::General_Error);
                    }

                    vector<float> floatsFromInputs = this->getFloatsFromPerceptionElementVector(
                            previousLayer.getOutputNodes());

                    Perception_Element_Matrix<Weight> currentLayersWeightsMatrix = currentLayer.getWeights();

                    Perception_Element_Vector<Node> currentLayersLocalNodes = currentLayer.getLocalNodes();

                    for (int i = 0; i < currentLayersWeightsMatrix.getRowSize(); i++) {

                        vector<float> floatsFromIndividualNodeWeights(
                                currentLayersWeightsMatrix.getElementRowAt(i).size()
                        );

                        floatsFromIndividualNodeWeights = this->getFloatsFromPerceptionElementVector(
                                currentLayersWeightsMatrix.getElementRowAt(i)
                                );



                        float currentNodesUnactivatedValue = perceptionMaths.dotProduct(floatsFromInputs,
                                                                                            floatsFromIndividualNodeWeights);


                        Node unactivatedNode(currentNodesUnactivatedValue);

                        currentLayersLocalNodes.setIndividualElement(i, unactivatedNode);
                     }

                    currentLayer.setLocalNodes(currentLayersLocalNodes);

                }
                catch (exception e) {
                    cout << "Error: " << e.what() << endl;
                }
            }

            void Layer_Helper::Prepare_Backward_Propagation(Layer &layer) {

            }

            const Perception_Maths &Layer_Helper::getPerceptionMaths() const {
                return perceptionMaths;
            }

            void Layer_Helper::setPerceptionMaths(const Perception_Maths &perceptionMaths) {
                Layer_Helper::perceptionMaths = perceptionMaths;
            }

            void Layer_Helper::Activate_Nodes_With_Softmax(Layer &layer ) {

                Perception_Element_Vector<Node> nodes = layer.getLocalNodes();

                double layersExponentialSum = this->Sum_The_Layers_Nodes_Exponential_Values(layer);

                for(int i; i < layer.getNodeCountPerLayer(); i++) {
                    Node currentNode = this->Activate_Node_With_Softmax(
                            nodes.getElementAt(i), layersExponentialSum);
                    nodes.setIndividualElement( i, currentNode);
                }

                layer.setLocalNodes(nodes);

            }

            void Layer_Helper::Activate_Nodes_With_ReLU(Layer &layer) {

  
                Perception_Element_Vector<Node> nodes = layer.getLocalNodes();

                for(int i; i < layer.getNodeCountPerLayer(); i++) {
                    Node currentNode = this->Activate_Node_With_ReLU( nodes.getElementAt(i));
                    nodes.setIndividualElement( i, currentNode);
                }

                layer.setLocalNodes(nodes);
            }

            // this function should not happen before the health of the vector is checked
            // so we can trust this will work
            // always check the health of the incoming vector first
            template<typename typeName>
            vector<float> Layer_Helper::getFloatsFromPerceptionElementVector(Perception_Element_Vector<typeName> elementType) {


                vector<float> floats(elementType.getElementVector().size());

                for(int i = 0; i < elementType.getElementVector().size(); i++) {
                    float value = ((Perception_Element)elementType.getElementAt(i)).getValue();
                    floats.at(i) =  value ;
                }

                return floats;

            }

            // this function should not happen before the health of the vector is checked
            // so we can trust this will work
            // always check the health of the incoming vector first
            template<typename typeName>
            vector<float> Layer_Helper::getFloatsFromPerceptionElementVector(vector<typeName> elementType) {


                vector<float> floats(elementType.size());

                for(int i = 0; i < elementType.size(); i++) {
                    float value = ((Perception_Element)elementType.at(i)).getValue();
                    floats.at(i) =  value ;
                }

                return floats;

            }

        } // Perception
    } // Network
} // Utilities