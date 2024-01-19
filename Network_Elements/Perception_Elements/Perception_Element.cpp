//
// Created by thome on 1/10/2024.
//

#include "Perception_Element.h"

namespace Perception {
    namespace Elements {

        /***
         * This constructor instantiates a random value to be set at runtime for updates
         * doing it in the constructor eliminates a significant amount of code necessary to accomplish
         * the same functionality
         *
         * BE AWARE -- the input values that are sent to the first layer should not use this constructor
         * as their values would not (that i can think of) be random. They would be real world values
         */
        Perception_Element::Perception_Element() {

            float randomValue = (float)rand() / ((float)RAND_MAX + 1) * 2 - 1;
            this->setValue(randomValue);

        }

        Perception_Element::Perception_Element(float value) : value(value) {}

        float Perception_Element::getValue() const {
            return value;
        }

        void Perception_Element::setValue(float value) {
            Perception_Element::value = value;
        }

        Perception_Element::~Perception_Element() {

        }

        Perception_Enumerations::healthStatus Perception_Element::getHealthStatus() const {
            return healthStatus;
        }

        void Perception_Element::setHealthStatus(Perception_Enumerations::healthStatus healthStatus) {
            Perception_Element::healthStatus = healthStatus;
        }

    } // Perception
} // Elements