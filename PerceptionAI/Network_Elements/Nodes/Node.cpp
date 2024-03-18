//
// Created by thome on 1/10/2024.
//

#include <exception>
#include "Node.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Nodes {
                Node::Node() {
                    this->setIsActivatedValueSet(false);
                    this->setIsDerivedValueSet(false);
                    this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                    this->addErrorMessage(Perception_Enumerations::errorMessages::Object_Exists_But_No_Value_Set);
                }

                Node::~Node() {
 
                }

                Node::Node(float value) : Perception_Element(value) {
                    this->setIsActivatedValueSet(false);
                    this->setIsDerivedValueSet(false);
                    this->setHealthStatus(Perception_Enumerations::healthStatus::ok);
                }

                vector<float> Node::getDerivedValues() {
                    try {

                        if(!this->checkIsDerivedValueSet()) { throw runtime_error("nope"); }
                        return derivedValues;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                    }

                    return derivedValues;
                }

                void Node::setDerivedValues(vector<float> derivedValue) {
                    this->derivedValues = derivedValue;
                    this->setIsDerivedValueSet(true);
                }

                float Node::getActivatedValue() {
                    try {

                        if(!this->checkIsActivatedValueSet()) { throw runtime_error("nope"); }
                        return activatedValue;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                    }
                    return activatedValue;
                }

                void Node::setActivatedValue(float activatedValue) {
                    Node::activatedValue = activatedValue;
                    this->setIsActivatedValueSet(true);

                }

                bool Node::checkIsDerivedValueSet() const {
                    return isDerivedValueSet;
                }

                void Node::setIsDerivedValueSet(bool isDerivedValueSet) {
                    Node::isDerivedValueSet = isDerivedValueSet;
                }

                bool Node::checkIsActivatedValueSet() const {
                    return isActivatedValueSet;
                }

                void Node::setIsActivatedValueSet(bool isActivatedValueSet) {
                    Node::isActivatedValueSet = isActivatedValueSet;
                }

            } // Perception
        } // Elements
    }
} // Nodes