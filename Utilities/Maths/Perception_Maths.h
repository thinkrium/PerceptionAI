//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_MATHS_H
#define PERCEPTIONAI_PERCEPTION_MATHS_H

#include "random"
#include "../../Network_Elements/Nodes/Node.h"
#include "../../Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.h"

using namespace Perception::Network::Elements::Matrices;
using namespace Perception::Network::Elements::Nodes;

namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace Maths {

                class Perception_Maths {

                private:
                    Perception_Element_Matrix invertMatrix(Perception_Element_Matrix matrixToInvert);

                public:
                    Perception_Maths();
                    virtual ~Perception_Maths();
                    /**
                     * Sets a random value between -1 and 1
                     */
                    float generateRandomValue();

                    Perception_Element_Matrix
                    dotProduct(Perception_Element_Matrix leftMatrix, Perception_Element_Matrix rightMatrix) ;
                };
            }
        } // Perception
    } // Utilities
} // Maths

#endif //PERCEPTIONAI_PERCEPTION_MATHS_H
