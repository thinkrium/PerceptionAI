//
// Created by thome on 1/22/2024.
//

#include "Perception_Element_Vector.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Vectors {
                template<class objectType>
                const vector<objectType> &Perception_Element_Vector<objectType>::getElementVector() const {
                    return element_vector;
                }

                template<class objectType>
                void Perception_Element_Vector<objectType>::setElementVector(const vector<objectType> &elementVector) {
                    element_vector = elementVector;
                }

                template<class objectType>
                void Perception_Element_Vector<objectType>::setIndividualElement(int index, objectType &element) {

                }

                template<class objectType>
                Perception_Element_Vector<objectType>::Perception_Element_Vector(int size):size(size) {
                    this->setElementVector(vector<objectType>(this->getSize()));
                }

                template<class objectType>
                Perception_Element_Vector<objectType>::~Perception_Element_Vector() = default;


                template<class objectType>
                int Perception_Element_Vector<objectType>::getSize() const {
                    return size;
                }

                template<class objectType>
                void Perception_Element_Vector<objectType>::setSize(int size) {
                    Perception_Element_Vector::size = size;
                }

                template<class objectType>
                Perception_Element_Vector<objectType>::Perception_Element_Vector() {}



            } // Perception
        } // Network
    } // Elements
} // Vectors