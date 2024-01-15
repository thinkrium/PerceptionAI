//
// Created by thome on 1/13/2024.
//


#include "Layer_Helper.h"


namespace Perception {
    namespace Network {
        namespace Utilities {


            vector<Node> Layer_Helper::Propagate_Forward() {
                return vector<Node>();
            }

            vector<Node> Layer_Helper::Propagate_Backward() {
                return vector<Node>();
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
            double Layer_Helper::Sum_The_Layers_Nodes_Exponential_Values(Layer layer) {
                
                double layersExponentialSum = 0;

                for each (Node node in layer.getLocalNodes()) 
                {
                    layersExponentialSum += exp( node.getValue());
                }

                return layersExponentialSum;

            }

            void Layer_Helper::Activate_Node_With_Softmax(Node& node) {

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
        } // Perception
    } // Network
} // Utilities