//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_BIAS_H
#define PERCEPTIONAI_BIAS_H

#include "../Perception_Elements/Perception_Element.h"

using namespace Perception::Elements;

namespace Perception {
    namespace Elements {
        namespace Biases {

            class Bias : Perception_Element {
            public:
                Bias();

                explicit Bias(float value);

                virtual ~Bias();
            };

        } // Perception
    } // Elements
} // Biases

#endif //PERCEPTIONAI_BIAS_H
