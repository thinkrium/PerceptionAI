//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_H

#include "cmath"

#include "../../Statuses/Status.h"
using namespace Perception::Network::Elements::Statuses;

using namespace std;

namespace Perception {
    namespace Network  {
    namespace Elements {

        class Perception_Element : public  Status {

        private:
        public:
            explicit Perception_Element(float value);

            Perception_Element();

            float getValue();

            void setValue(float value);

            bool isValueIsSet() const;

            void setValueIsSet(bool valueIsSet);


            virtual ~Perception_Element();

        private:
            float value;
            bool valueIsSet;

        };
    }
    } // Perception
} // Elements

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_H
