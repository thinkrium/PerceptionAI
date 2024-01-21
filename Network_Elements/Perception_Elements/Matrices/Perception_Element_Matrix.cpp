//
// Created by thome on 1/19/2024.
//

#include "Perception_Element_Matrix.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Matrices {
                Perception_Element_Matrix::Perception_Element_Matrix() {}

                /**
                 * not zero based indexing declare with +1 for readability
                 * @param rowSize
                 * @param colSize
                 */
                Perception_Element_Matrix::Perception_Element_Matrix(int rowSize, int colSize) : rowSize(rowSize),
                                                                                                 colSize(colSize) {

                    this->setRowSize(rowSize - 1);
                    this->setColSize(colSize - 1);



                    this->setMatrix(vector< vector<Perception_Element>>  (
                            this->getRowSize(),
                            vector<Perception_Element> (this->getColSize())));
                }

                const vector<vector<Perception_Element>> &Perception_Element_Matrix::getMatrix() const {
                    return matrix;
                }

                void Perception_Element_Matrix::setMatrix(const vector<vector<Perception_Element>> &matrix) {
                    Perception_Element_Matrix::matrix = matrix;
                }

                int Perception_Element_Matrix::getRowSize() const {
                    return rowSize;
                }

                void Perception_Element_Matrix::setRowSize(int rowSize) {
                    Perception_Element_Matrix::rowSize = rowSize;
                }

                int Perception_Element_Matrix::getColSize() const {
                    return colSize;
                }

                void Perception_Element_Matrix::setColSize(int colSize) {
                    Perception_Element_Matrix::colSize = colSize;
                }

                Perception_Element_Matrix::~Perception_Element_Matrix() {

                }

                void Perception_Element_Matrix::setIndividualMatrixElement(int rowSize, int columnSize,
                                                                           Perception_Element element) {

                    this->matrix[rowSize][columnSize] = element;

                }
            } // Perception
        } // Network
    } // Elements
} // Matrices