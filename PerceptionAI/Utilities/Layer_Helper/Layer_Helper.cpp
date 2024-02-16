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

            void Layer_Helper::Activate_Node_With_ReLU(Node &node) {
                try {
                    if(!node.isValueIsSet()) {throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Value_Set);}
                    if (node.getValue() <= 0) {
                        node.setValue(0);
                    }
                }
                catch (exception e) {
                    node.setHealthStatus(Perception_Enumerations::healthStatus::error);
                    node.addErrorMessage(e.what());
                }

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

            void Layer_Helper::Activate_Node_With_Softmax(Node& node, double layersExponentialSum) {
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

            }

            void Layer_Helper::Calculate_Loss_With_Categorical_Cross_Entropy() {

            }

            void Layer_Helper::Calculate_Derivative_Of_ReLu() {

            }

            void Layer_Helper::Calculate_Derivative_Of_Softmax() {

            }

            void Layer_Helper::Calculate_Categorical_Cross_Entropy_Derivative() {

            }

            void Layer_Helper::Calculate_Cross_Entropy_With_Softmax_Derivative() {

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
                            this->Activate_Nodes_With_Softmax(layer);
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

            void Layer_Helper::Activate_Nodes_With_Softmax(Layer &layer) {

            }

            void Layer_Helper::Activate_Nodes_With_ReLU(Layer &layer) {
                for(int i; i < layer.getNodeCountPerLayer(); i++) {
//                    this->Activate_Node_With_ReLU( );
                }

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