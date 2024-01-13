//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_LAYER_HELPER_H
#define PERCEPTIONAI_LAYER_HELPER_H

#include "../../Network_Elements/Layers/Layer.h"

namespace Perception {
    namespace Network {
        namespace Utilities {

            class Layer_Helper {

                static vector<Node> Propagate_Forward();
                static vector<Node> Propagate_Backward();
                static void Activate_Node_With_ReLU();
                static void Activate_Node_With_Softmax();
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
