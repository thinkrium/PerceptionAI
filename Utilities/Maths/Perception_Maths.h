//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_MATHS_H
#define PERCEPTIONAI_PERCEPTION_MATHS_H

#include "random"
#include "../../Network_Elements/Nodes/Node.h"

using namespace Perception::Network::Elements::Nodes;

namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace Maths {

                class Perception_Maths {

                private:
                    vector<vector<Perception_Element>> invertMatrix(vector<vector<Perception_Element>> matrixToInvert);

                public:
                    Perception_Maths();
                    virtual ~Perception_Maths();
                    /**
                     * Sets a random value between -1 and 1
                     */
                    float generateRandomValue();

                    vector<vector<Perception_Element>> dotProduct(vector<vector<Perception_Element>> leftMatrix, vector<vector<Perception_Element>> rightMatrix) ;


                    float dotProduct(vector<float> leftVector, vector<float> rightVector);
                };
            }
        } // Perception
    } // Utilities
} // Maths

#endif //PERCEPTIONAI_PERCEPTION_MATHS_H
