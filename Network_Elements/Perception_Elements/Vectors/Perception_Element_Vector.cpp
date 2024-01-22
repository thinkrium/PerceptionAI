//
// Created by thome on 1/22/2024.
//

#include "Perception_Element_Vector.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Vectors {
                Perception_Element_Vector::Perception_Element_Vector() {}

                Perception_Element_Vector::~Perception_Element_Vector() {

                }

                const vector<Perception_Element> &Perception_Element_Vector::getElementVector() const {
                return element_vector;
                }

                void Perception_Element_Vector::setElementVector(const vector<Perception_Element> &elementVector) {
                    element_vector = elementVector;
                }

                int Perception_Element_Vector::getSize() const {
                    return size;
                }

                /**
                 * not zero based
                 * @param size
                 */
                void Perception_Element_Vector::setSize(int size) {
                    Perception_Element_Vector::size = size;
                }

                void Perception_Element_Vector::setIndividualElement(int index, Perception_Element element) {
                       this->element_vector[index] = element;
                }

                /**
                 * not zero based
                 * @param size
                 */
                Perception_Element_Vector::Perception_Element_Vector(int size) : size(size) {
                    this->setSize(size);

                    this->setElementVector(vector<Perception_Element>(this->getSize()));
                }
            } // Perception
        } // Network
    } // Elements
} // Vectors