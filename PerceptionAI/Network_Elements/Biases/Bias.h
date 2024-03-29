//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_BIAS_H
#define PERCEPTIONAI_BIAS_H

#include "../Perception_Elements/Individual/Perception_Element.h"

using namespace Perception::Network::Elements;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Biases {

                class Bias : public Perception_Element {
                public:
                    Bias();

                    explicit Bias(float value);

                    ~Bias() override;
                };

            } // Perception
        }
    } // Elements
} // Biases

#endif //PERCEPTIONAI_BIAS_H
