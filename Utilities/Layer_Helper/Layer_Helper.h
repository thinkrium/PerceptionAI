//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_LAYER_HELPER_H
#define PERCEPTIONAI_LAYER_HELPER_H

#include "../../Network_Elements/Layers/Layer.h"
#include "../../Network_Elements/Nodes/Node.h"
#include "../../Network_Elements/Weights/Weight.h"
#include "../../Network_Elements/Biases/Bias.h"

#include "cmath"

using namespace Perception::Elements::Nodes;
using namespace Perception::Elements::Weights;
using namespace Perception::Elements::Biases;

using namespace Perception::Layers;

using namespace std;

namespace Perception {
    namespace Network {
        namespace Utilities {

            class Layer_Helper {

                static vector<Node> Propagate_Forward();
                static vector<Node> Propagate_Backward();
                static void Activate_Node_With_ReLU(Node &node);
                static double Sum_The_Layers_Nodes_Exponential_Values(Layer layer);
                static void Activate_Node_With_Softmax(Node& node, double layersExponentialSum);
                static void Calculate_Loss_With_Categorical_Cross_Entropy();
                static void Calculate_Derivative_Of_ReLu();
                static void  Calculate_Derivative_Of_Softmax();
                static void Calculate_Categorical_Cross_Entropy_Derivative();
                static void  Calculate_Cross_Entropy_With_Softmax_Derivative();

            };

        } // Perception
    } // Network
} // Utilities

#endif //PERCEPTIONAI_LAYER_HELPER_H
