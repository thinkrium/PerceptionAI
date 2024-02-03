//
// Created by thome on 1/17/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ENUMERATIONS_H
#define PERCEPTIONAI_PERCEPTION_ENUMERATIONS_H

#include "map"
#include "iostream"

using namespace std;
namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace Enumerations {

                class Perception_Enumerations {

                public:
                      enum activationMethod {ReLU, Softmax, Sigmoid};
                      enum lossCalculationMethod { CategoricalCrossEntropy };
                      enum healthStatus { ok, error };
//                      map<string, string > errorMessages = {
//                              "General Error", "There is a General error"
//                      };
                };

            } // Perception
        } // Network
    } // Utilities
} // Enumerations

#endif //PERCEPTIONAI_PERCEPTION_ENUMERATIONS_H
