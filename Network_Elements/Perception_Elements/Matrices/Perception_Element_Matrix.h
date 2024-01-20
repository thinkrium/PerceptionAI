//
// Created by thome on 1/19/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H

#include <vector>
#include "../Individual/Perception_Element.h"

#include "../../Statuses/Status.h"

using namespace Perception::Network::Elements::Statuses;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Matrices {

                template<typename t> class Perception_Element_Matrix : public Status {
                public:
                private:

                    vector<vector<t>> matrix;
                    int rowSize;
                    int columnSize;
                public:
                    Perception_Element_Matrix();

                    void setIndividualMatrixElementValue(int rowIndex, int columnIndex, float value);
                    Perception_Element_Matrix(int rowSize, int columnSize);

                    int getRowSize() const;

                    void setRowSize(int rowSize);

                    int getColumnSize() const;

                    void setColumnSize(int columnSize);

                    ~Perception_Element_Matrix() override;

                    const vector<vector<t>> &getMatrix() const;

                    void setMatrix(const vector<vector<t>> &matrix);
                };

            } // Perception
        } // Network
    } // Elements
} // Matrices

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H
