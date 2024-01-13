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

                static vector<Node> Propagate_Forward()
                Propagate_Backward()
                Activate_Node_With_ReLU()
                Activate_Node_With_Softmax()
                Calculate_Loss_With_Categorical_Cross_Entropy()
                Calculate_Derivative_Of_ReLu()
                Calculate_Derivative_Of_Softmax()
                Calculate_Categorical_Cross_Entropy_Derivative()
                Calculate_Cross_Entropy_With_Softmax_Derivative()

            };

        } // Perception
    } // Network
} // Utilities

#endif //PERCEPTIONAI_LAYER_HELPER_H
