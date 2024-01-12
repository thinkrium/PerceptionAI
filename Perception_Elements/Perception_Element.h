//
// Created by thome on 1/10/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_H

namespace Perception {
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
        };

    } // Perception
} // Elements

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_H
