//
// Created by thome on 1/13/2024.
//

#include "Perception_Maths.h"
#include "cstdlib"
#include "ctime"

namespace Perception {
    namespace Utilities {
        namespace Maths {
            float Perception_Maths::generateRandomValue() {
//                std::default_random_engine generator;
//                std::uniform_real_distribution<float> distribution(-1,1);
//
//                float randomNumber  =   distribution(generator);

                  float randomNumber = (float)rand() / ((float)RAND_MAX + 1) * 2 - 1;

                return randomNumber;
            }
        } // Perception
    } // Utilities
} // Maths