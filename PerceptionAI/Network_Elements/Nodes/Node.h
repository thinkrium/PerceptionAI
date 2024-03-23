//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_NODE_H
#define PERCEPTIONAI_NODE_H

#include "../Perception_Elements/Individual/Perception_Element.h"

using namespace Perception::Network::Elements;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Nodes {

                class Node : public Perception_Element {
                public:
                    float getDerivedValue();

                    void setDerivedValue(float derivedValue);

                    float getActivatedValue();

                    void setActivatedValue(float activatedValue);

                private:

                    float derivedValue;

                    float activatedValue;
                public:
                    bool checkIsDerivedValueSet() const;

                    void setIsDerivedValueSet(bool isDerivedValueSet);

                    bool checkIsActivatedValueSet() const;

                    void setIsActivatedValueSet(bool isActivatedValueSet);

                private:
                    bool isDerivedValueSet;
                    bool isActivatedValueSet;

                public:
                    Node();

                    explicit Node(float value);

                    ~Node() override;
                };

            } // Perception
        } // Elements
    }
} // Nodes

#endif //PERCEPTIONAI_NODE_H
