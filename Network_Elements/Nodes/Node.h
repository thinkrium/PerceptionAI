//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_NODE_H
#define PERCEPTIONAI_NODE_H

#include "../Perception_Elements/Perception_Element.h"

using namespace Perception::Elements;

namespace Perception {
    namespace Elements {
        namespace Nodes {

            class Node : public Perception_Element {
            public:
                Node();

                explicit Node(float value);

                virtual ~Node();
            };

        } // Perception
    } // Elements
} // Nodes

#endif //PERCEPTIONAI_NODE_H