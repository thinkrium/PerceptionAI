//
// Created by thome on 1/10/2024.
//

#include <exception>
#include "Perception_Element.h"

namespace Perception {
    namespace Network {
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

                float randomValue = (float) rand() / ((float) RAND_MAX + 1) * 2 - 1;
                this->setValue(randomValue);
                this->setHealthStatus(Perception_Enumerations::healthStatus::ok);
            }

            Perception_Element::Perception_Element(float value) : value(value) {
                this->setValue(value);
                this->setHealthStatus(Perception_Enumerations::healthStatus::ok);
            }


            float Perception_Element::getValue() {
                try {

                    if(!this->isValueIsSet()) { throw runtime_error("nope"); }
                    return value;
                }
                catch (exception e) {
                      this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                    return value;
                }
            }

            void Perception_Element::setValue(float value) {
                Perception_Element::value = value;
                this->setValueIsSet(true);
            }

            Perception_Element::~Perception_Element() {

            }

            bool Perception_Element::isValueIsSet() const {
                return valueIsSet;
            }

            void Perception_Element::setValueIsSet(bool valueIsSet) {
                Perception_Element::valueIsSet = valueIsSet;
            }

            bool Perception_Element::operator == (const Perception_Element& incomingPerceptionElement) const
            {
                if (
                        valueIsSet == incomingPerceptionElement.valueIsSet
                        &&
                        value == incomingPerceptionElement.value
                    )
                    return true;
                return false;
            }
        }
    } // Perception
} // Elements