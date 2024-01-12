//
// Created by thome on 1/10/2024.
//

#include "Perception_Element.h"

namespace Perception {
    namespace Elements {
        Perception_Element::Perception_Element() {}

        Perception_Element::Perception_Element(float value) : value(value) {}

        float Perception_Element::getValue() const {
            return value;
        }

        void Perception_Element::setValue(float value) {
            Perception_Element::value = value;
        }

        Perception_Element::~Perception_Element() {

        }
    } // Perception
} // Elements