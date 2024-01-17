//
// Created by thome on 1/17/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ENUMERATIONS_H
#define PERCEPTIONAI_PERCEPTION_ENUMERATIONS_H

namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace Enumerations {

                class Perception_Enumerations {

                public:
                      enum activationMethod {ReLU, Softmax, Sigmoid};
                      enum lossCalculationMethod { CategoricalCrossEntropy };
                };

            } // Perception
        } // Network
    } // Utilities
} // Enumerations

#endif //PERCEPTIONAI_PERCEPTION_ENUMERATIONS_H
