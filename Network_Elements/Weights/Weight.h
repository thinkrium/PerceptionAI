//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_WEIGHT_H
#define PERCEPTIONAI_WEIGHT_H

#include "../Perception_Elements/Individual/Perception_Element.h"

using namespace Perception::Network::Elements;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Weights {

                class Weight : public Perception_Element {
                public:
                    Weight();

                    explicit Weight(float value);

                    ~Weight() override;

                };


            } // Perception
        } // Elements
    }
} // Weights

#endif //PERCEPTIONAI_WEIGHT_H
