//
// Created by thome on 1/22/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H

#include "../../Statuses/Status.h"
#include "../Individual/Perception_Element.h"
#include "vector"

using namespace Perception::Network::Elements;
using namespace Perception::Network::Elements::Statuses;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Vectors {

                class Perception_Element_Vector : public Status {
                public:
                    explicit Perception_Element_Vector(int size);

                private:
                    vector<Perception_Element> element_vector;

                    int size;
                public:
                    ~Perception_Element_Vector() override;

                public:
                    Perception_Element_Vector();

                    const vector<Perception_Element> &getElementVector() const;

                    void setIndividualElement(int index, Perception_Element element);

                    void setElementVector(const vector<Perception_Element> &elementVector);

                    int getSize() const;

                    void setSize(int size);
                };

            } // Perception
        } // Network
    } // Elements
} // Vectors

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H
