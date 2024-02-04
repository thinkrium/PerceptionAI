//
//
// Created by thome on 1/22/2024.

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H

#include "../../Statuses/Status.h"
#include "../Individual/Perception_Element.h"
#include "vector"
#include "memory"
#include "iostream"

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

                    bool sizeIsSet;

                    bool elementVectorIsSet;
                public:

                    bool isElementVectorIsSet() const {
                        return elementVectorIsSet;
                    }

                    void setElementVectorIsSet(bool elementVectorIsSet) {
                        Perception_Element_Vector::elementVectorIsSet = elementVectorIsSet;
                    }

                public:
                    bool isSizeIsSet() const {
                        return sizeIsSet;
                    }

                    void setSizeIsSet(bool sizeIsSet) {
                        Perception_Element_Vector::sizeIsSet = sizeIsSet;
                    }

                public:

                    Perception_Element_Vector() {

                        this->setSizeIsSet(false);

                        this->setElementVectorIsSet(false);

                        // we don't know the size
                        // we don't have a vector
                        // health status - error
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                    }

                    explicit Perception_Element_Vector(int size) {

                        this->setSize(size);
                        this->element_vector = vector<objectType> (this->getSize());
                        this->setHealthStatus(Perception_Enumerations::healthStatus::ok);
                    }

                    void setIndividualElement(int index, objectType &element) {
                        try {
                            if(!this->isSizeIsSet()) {throw runtime_error("nope");}

                            this->element_vector[index] = element;
                        }
                        catch (exception e) {
                            cout << "error: " << e.what() << endl;
                            this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        }
                    }



                    ~Perception_Element_Vector() override {}


                    int getSize()  {
                        try {

                            if(!this->isSizeIsSet()) { throw runtime_error("nope"); }
                            return this->size;
                        }
                        catch (exception e) {

                            Status::setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }

                        return this->size;
                    }

                    void setSize(int size) {
                        this->size = size;
                        this->setSizeIsSet(true);
                    }

                     vector<objectType> &getElementVector()  {
                        try {

                            if(!this->isElementVectorIsSet()) { throw runtime_error("nope"); }
                            return this->element_vector;
                        }
                        catch (exception e) {
                               this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }
                        return this->element_vector;
                    }

                    objectType getElementAt(int index) {
                        try {

                            if(
                                !(
                                    this->isElementVectorIsSet()
                                     &&
                                    this->getSize() > index
                                )
                             ) { throw runtime_error("nope"); }
                            return this->getElementVector().at(index);
                        }
                        catch (exception e) {
                            this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }

                        return this->getElementVector().at(index);
                    }
                    void setElementVector(const vector<objectType> &elementVector) {
                        this->element_vector = elementVector;
                        this->setElementVectorIsSet(true);
                    }
                };

            } // Perception
        } // Network
    } // Elements
} // Vectors

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H
