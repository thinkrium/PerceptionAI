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
                        this->addErrorMessage(Perception_Enumerations::errorMessages::Object_Exists_But_No_Value_Set);
                    }

                    explicit Perception_Element_Vector(int size) {

                        this->setSize(size);
                        this->setHealthStatus(Perception_Enumerations::healthStatus::ok);

                        if(this->getSize() == 0) {
                            this->setElementVector(  vector<objectType> ());

                        }
                        else if(this->getSize() > 0) {
                            this->setElementVector(  vector<objectType> (this->getSize()));

                        }
                        else {
                            this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                            this->addErrorMessage(Perception_Enumerations::errorMessages::Perception_Failed_To_Set_A_Value);
                        }

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

                    void add_element_to_end_of_vector(objectType element) {
                         this->getElementVector().push_back(element);
                         this->updateSize();
                    }

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

                    void updateSize() {
                        this->setSize(this->element_vector.size());
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

                        this->setSize(elementVector.size());
                    }

                    bool operator==(const Perception_Element_Vector &rhs) const {
                        return static_cast<const Status &>(*this) == static_cast<const Status &>(rhs) &&
                               element_vector == rhs.element_vector &&
                               size == rhs.size &&
                               sizeIsSet == rhs.sizeIsSet &&
                               elementVectorIsSet == rhs.elementVectorIsSet;
                    }

                    bool operator!=(const Perception_Element_Vector &rhs) const {
                        return !(rhs == *this);
                    }
                };

            } // Perception
        } // Network
    } // Elements
} // Vectors

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_VECTOR_H
