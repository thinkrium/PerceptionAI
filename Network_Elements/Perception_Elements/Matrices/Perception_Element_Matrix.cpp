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
                                                                                                 columnSize(colSize) {

                    this->setRowSize(rowSize);
                    this->setColumnSize(colSize);



                    this->setMatrix(vector< vector<Perception_Element>>  (
                            this->getRowSize(),
                            vector<Perception_Element> (this->getColumnSize())));
                }

                const vector<vector<Perception_Element>> &Perception_Element_Matrix::getMatrix() const {
                    return element_matrix;
                }

                void Perception_Element_Matrix::setMatrix(const vector<vector<Perception_Element>> &matrix) {
                    Perception_Element_Matrix::element_matrix = matrix;
                }

                int Perception_Element_Matrix::getRowSize() const {
                    return rowSize;
                }

                void Perception_Element_Matrix::setRowSize(int rowSize) {
                    Perception_Element_Matrix::rowSize = rowSize;
                }

                int Perception_Element_Matrix::getColumnSize() const {
                    return columnSize;
                }

                void Perception_Element_Matrix::setColumnSize(int colSize) {
                    Perception_Element_Matrix::columnSize = colSize;
                }

                Perception_Element_Matrix::~Perception_Element_Matrix() {

                }

                void Perception_Element_Matrix::setIndividualElement(int rowIndex, int columnIndex,
                                                                     Perception_Element element) {

                    this->element_matrix[rowIndex][columnIndex] = element;

                }


                Perception_Element_Matrix
                Perception_Element_Matrix::transpose(
                        Perception::Network::Elements::Matrices::Perception_Element_Matrix matrixToTranspose) {

                    int rowSize = matrixToTranspose.getMatrix().size();
                    int columnSize = matrixToTranspose.getMatrix()[0].size();

                    // you have to add 1 to the index size because for readability they are not zero indexed
                    // hovering over the function name will reveal the tool tip
                    Perception_Element_Matrix transposedMatrix((rowSize + 1) , (columnSize + 1));

                    for(int rowIndex = 0; rowIndex < rowSize; rowIndex++) {
                        for(int columnIndex = 0 ; columnIndex < columnSize; columnIndex++) {

                            transposedMatrix.setIndividualElement(columnIndex,
                                                                  rowIndex,
                                                                  matrixToTranspose.getMatrix()[rowIndex][columnIndex]);
                        }
                    }

                    return transposedMatrix;
                }
            } // Perception
        } // Network
    } // Elements
} // Matrices