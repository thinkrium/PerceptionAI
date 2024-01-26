//
// Created by thome on 1/22/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H

#include "../../Statuses/Status.h"
#include "../Individual/Perception_Element.h"
#include "vector"
#include "memory"

using namespace Perception::Network::Elements;
using namespace Perception::Network::Elements::Statuses;
using namespace std;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Vectors {

                template<class objectType>
                class Perception_Element_Vector : public Status {

                private:
                    vector< objectType> element_vector;

                    int size;
                public:

                    Perception_Element_Vector() {

                    }

                    explicit Perception_Element_Vector(int size) {

                    }

                    void setIndividualElement(int index, objectType &element) {}



                    ~Perception_Element_Vector() override {}


                    int getSize() const {
                        return this->size;
                    }

                    void setSize(int size) {}

                    const vector<objectType> &getElementVector() const {
                        return this->element_vector;
                    }

                    void setElementVector(const vector<objectType> &elementVector) {}
                };

            } // Perception
        } // Network
    } // Elements
} // Vectors

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H
