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
                }

                Node::~Node() {
 
                }

                Node::Node(float value) : Perception_Element(value) {
                    this->setIsActivatedValueSet(false);
                    this->setIsDerivedValueSet(false);
                    this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                }

                float Node::getDerivedValue() {
                    try {

                        if(!this->checkIsDerivedValueSet()) { throw "nope"; }
                        return derivedValue;
                    }
                    catch (exception e) {
                        this->setHealthStatusIsSet(Perception_Enumerations::healthStatus::error);

                    }

                    return derivedValue;
                }

                void Node::setDerivedValue(float derivedValue) {
                    Node::derivedValue = derivedValue;
                    this->setIsDerivedValueSet(true);
                }

                float Node::getActivatedValue() {
                    try {

                        if(!this->checkIsActivatedValueSet()) { throw "nope"; }
                        return activatedValue;
                    }
                    catch (exception e) {
                        this->setHealthStatusIsSet(Perception_Enumerations::healthStatus::error);

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