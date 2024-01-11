//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_WEIGHT_H
#define PERCEPTIONAI_WEIGHT_H

#include "../Perception_Elements/Perception_Element.h"

using namespace Perception::Elements;

namespace Perception {
    namespace Elements {
        namespace Weights {

            class Weight : public Perception_Element {
            public:
                Weight();

                explicit Weight(float value);

            };

        } // Perception
    } // Elements
} // Weights

#endif //PERCEPTIONAI_WEIGHT_H
