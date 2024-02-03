 //
// Created by thome on 1/13/2024.
//


#include "Layer_Helper.h"


namespace Perception {
    namespace Network {
        namespace Utilities {


            /**
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
                if (node.getValue() <= 0) {
                    node.setValue(0);
                }
            }

            /// <summary>
            /// activation with softmax is dependent on an exponential sum
            /// </summary>
            /// <param name="layer"></param>
            double Layer_Helper::Sum_The_Layers_Nodes_Exponential_Values(Layer &layer) {
                
                double layersExponentialSum = 0;


//                for(int nodeIndex = 0; nodeIndex < layer.getLocalNodes().getSize(); nodeIndex++)
//                {
////                    layersExponentialSum += exp( layer.getLocalNodes().getElementVector()[nodeIndex].getValue());
//                }
//
                return layersExponentialSum;


            }

            void Layer_Helper::Activate_Node_With_Softmax(Node& node, double layersExponentialSum) {

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

            void Layer_Helper::Activate_Nodes_With(Perception_Enumerations::activationMethod activationMethod) {

            }

            void Layer_Helper::Prepare_Forward_Propagation(Layer &previousLayer, Layer &currentLayer) {

                vector<float> floatsFromInputs = this->getFloatsFromPerceptionElementVector(previousLayer.getOutputNodes());

                Perception_Element_Matrix<Weight> currentLayersWeights = currentLayer.getWeights();

                for(int i = 0; i < currentLayersWeights.getRowSize(); i++) {
                    vector<float> floatsFromIndividualNodeWeights(
                            currentLayersWeights.getElementRowAt(i).size()
                            );

                    for(int j = 0; j < currentLayersWeights.getElementRowAt(i).size(); j++) {
                        floatsFromIndividualNodeWeights.push_back(
                                currentLayersWeights.getElementAt(i, j).getValue()
                        );

                        float currentNodesUnactivatedValue = perceptionMaths.dotProduct(floatsFromInputs,floatsFromIndividualNodeWeights);

                        Perception_Element_Vector<Node> currentLayersLocalNodes = currentLayer.getLocalNodes();

                        Node unactivatedNode(currentNodesUnactivatedValue);

                        currentLayersLocalNodes.setIndividualElement(i, unactivatedNode);
                    }
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

            // this function should not happen before the health of the vector is checked
            // so we can trust this will work
            // always check the health of the incoming vector first
            template<typename typeName>
            vector<float> Layer_Helper::getFloatsFromPerceptionElementVector(Perception_Element_Vector<typeName> elementType) {


                vector<float> floats(elementType.getElementVector().size());

                for(int i = 0; i < elementType.getElementVector().size(); i++) {
                    float value = ((Perception_Element)elementType.getElementAt(i)).getValue();
                    floats.push_back(value);
                }

                return floats;

            }

        } // Perception
    } // Network
} // Utilities