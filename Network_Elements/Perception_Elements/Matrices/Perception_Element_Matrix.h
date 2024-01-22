//
// Created by thome on 1/19/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H

#include "../Individual/Perception_Element.h"
#include "../../Statuses/Status.h"

#include "vector"

using namespace std;

using namespace Perception::Network::Elements::Statuses;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Matrices {

                class Perception_Element_Matrix : public Status {
                private:
                    vector<vector<Perception_Element>> element_matrix;

                    int rowSize;

                    int columnSize;


                public:
                    Perception_Element_Matrix();

                    Perception_Element_Matrix(int rowSize, int colSize);

                    const vector<vector<Perception_Element>> &getMatrix() const;

                    void setIndividualElement(int rowIndex, int columnIndex, Perception_Element element);

                    Perception_Element_Matrix transpose(Perception_Element_Matrix matrixToTranspose);

                    void setMatrix(const vector<vector<Perception_Element>> &matrix);

                    int getRowSize() const;

                    void setRowSize(int rowSize);

                    int getColumnSize() const;

                    void setColumnSize(int colSize);

                    ~Perception_Element_Matrix() override;

                };

            } // Perception
        } // Network
    } // Elements
} // Matrices

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H
