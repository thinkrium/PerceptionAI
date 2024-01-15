//
// Created by thome on 1/10/2024.
//

#include "Node.h"

namespace Perception {
    namespace Elements {
        namespace Nodes {
            Node::Node() {}

            Node::~Node() {

            }

            Node::Node(float value) : Perception_Element(value) {}

            float Node::getDerivedValue() const {
                return derivedValue;
            }

            void Node::setDerivedValue(float derivedValue) {
                Node::derivedValue = derivedValue;
            }

            float Node::getActivatedValue() const {
                return activatedValue;
            }

            void Node::setActivatedValue(float activatedValue) {
                Node::activatedValue = activatedValue;
            }

        } // Perception
    } // Elements
} // Nodes