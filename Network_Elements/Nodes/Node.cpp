//
// Created by thome on 1/10/2024.
//

#include "Node.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Nodes {
                Node::Node() {
                    this->setIsActivatedValueSet(false);
                    this->setIsDerivedValueSet(false);
                }

                Node::~Node() {
 
                }

                Node::Node(float value) : Perception_Element(value) {
                    this->setIsActivatedValueSet(false);
                    this->setIsDerivedValueSet(false);
                }

                float Node::getDerivedValue() const {
                    return derivedValue;
                }

                void Node::setDerivedValue(float derivedValue) {
                    Node::derivedValue = derivedValue;
                    this->setIsDerivedValueSet(true);
                }

                float Node::getActivatedValue() const {
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