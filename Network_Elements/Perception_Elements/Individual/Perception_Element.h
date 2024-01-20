//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_H

#include "cmath"
#include "../../../Utilities/Enumerations/Perception_Enumerations.h"

using namespace Perception::Network::Utilities::Enumerations;
using namespace std;

namespace Perception {
    namespace Network  {
    namespace Elements {

        class Perception_Element {

        private:
        public:
            explicit Perception_Element(float value);

            Perception_Element();

            float getValue() const;

            void setValue(float value);


            virtual ~Perception_Element();

        private:
            float value;

            Perception_Enumerations::healthStatus healthStatus;
        public:
            Perception_Enumerations::healthStatus getHealthStatus() const;

            void setHealthStatus(Perception_Enumerations::healthStatus healthStatus);

        };
    }
    } // Perception
} // Elements

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_H
