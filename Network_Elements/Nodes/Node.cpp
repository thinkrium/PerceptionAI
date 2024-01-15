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

            void Node::setDerivedValue(float derivedValue)
            {
                this->derivedValue = derivedValue;
            }

            float Node::getDerivedValue()
            {
                return this->derivedValue;
            }

            void Node::setActivatedValue(float activatedValue)
            {
                this->activatedValue = activatedValue;
            }

            float Node::getActivatedValue()
            {
                return this->activatedValue;
            }

        } // Perception
    } // Elements
} // Nodes