//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_MATHS_H
#define PERCEPTIONAI_PERCEPTION_MATHS_H

#include "cstdlib"
#include "ctime"

#include "random"

#include "../../Network_Elements/Perception_Elements/Individual/Perception_Element.h"

#include "../../Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.h"

using namespace Perception::Network::Elements;
using namespace Perception::Network::Elements::Matrices;

namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace Maths {

                class Perception_Maths {

                private:
                    template<typename t>Perception_Element_Matrix<t> invertMatrix(Perception_Element_Matrix<t> matrixToInvert);

                public:
                    Perception_Maths();
                    virtual ~Perception_Maths();
                    /**
                     * Sets a random value between -1 and 1
                     */
                    float generateRandomValue();

                    template<typename t>Perception_Element_Matrix<t>
                    dotProduct(
                            Perception_Element_Matrix<t> leftMatrix,
                            Perception_Element_Matrix<t> rightMatrix
                            ) ;
                };
            }
        } // Perception
    } // Utilities
} // Maths

#endif //PERCEPTIONAI_PERCEPTION_MATHS_H
