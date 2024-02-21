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

         public:
            explicit Perception_Element(float value);

            Perception_Element();

            float getValue();

            void setValue(float value);

            bool isValueIsSet() const;

            void setValueIsSet(bool valueIsSet);

            bool operator==(const Perception_Element& incomingPerceptionElement) const;
            
            virtual ~Perception_Element();

        private:
            float value;
            bool valueIsSet;
            string UUID;
            bool UUID_is_set;
        public:
            bool isUuidIsSet() const;

            void setUuidIsSet(bool uuidIsSet);

        public:
            const string &getUuid() const;

            void setUuid(const string &uuid);
        };
    }
    } // Perception
} // Elements

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_H
