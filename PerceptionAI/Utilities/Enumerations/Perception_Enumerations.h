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
                      struct errorMessages {
                          inline static string General_Error = "There is a General error";
                          inline static string Object_Exists_But_No_Value_Set = "The object exists but no value is set";
                          inline static string Object_Exists_But_No_Activated_Value_Set = "The object exists but no activated value is set";
                          inline static string Object_Exists_But_No_Derived_Value_Set = "The object exists but no derived value is set";
                          inline static string Object_Exists_But_No_Loss_Value_Set = "The object exists but no loss value is set";
                          inline static string Layer_Helper_Attempted_Activation_But_Failed = "Layer Helper Attempted Activation But Failed";
                      };
                };

            } // Perception
        } // Network
    } // Utilities
} // Enumerations

#endif //PERCEPTIONAI_PERCEPTION_ENUMERATIONS_H
