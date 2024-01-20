//
// Created by thome on 1/19/2024.
//

#include "Perception_Element_Matrix.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Matrices {

                /**
                 * describe the shape of the matrix xof perception elements; rowSize and columnSize are
                 * not zero based they start at index 1 for readability
                 * so when creating the matrix you must subtract 1
                 *
                 *   if you have 1 row then rowsize should read 1 not 0
                 * @param rowSize
                 * @param columnSize
                 */
                template<typename t>
                Perception_Element_Matrix<t>::Perception_Element_Matrix(int rowSize, int columnSize) : rowSize(rowSize),
                                                                                                    columnSize(
                                                                                                            columnSize) {

                    this->setRowSize(rowSize - 1);
                    this->setColumnSize(columnSize - 1);
                    this->setMatrix(
                            vector<vector<Perception_Element>>(
                                    this->getRowSize(),
                                    vector<Perception_Element>(this->getColumnSize())
                                    )
                                );
                }

                /**
                 * describe the shape of the matrix xof perception elements; rowSize and columnSize are
                 * not zero based they start at index 1 for readability
                 * so when creating the matrix you must subtract 1
                 *
                 *   if you have 1 row then rowsize should read 1 not 0

                 * @return
                 */
                template<typename t>
                int Perception_Element_Matrix<t>::getRowSize() const {
                    return rowSize;
                }

                /**
                 * describe the shape of the matrix xof perception elements; rowSize and columnSize are
                 * not zero based they start at index 1 for readability
                 * so when creating the matrix you must subtract 1
                 *
                 *   if you have 1 row then rowsize should read 1 not 0

                 * @return
                 */
                template<typename t>
                void Perception_Element_Matrix<t>::setRowSize(int rowSize) {
                    Perception_Element_Matrix::rowSize = rowSize;
                }

                /**
                 * describe the shape of the matrix xof perception elements; rowSize and columnSize are
                 * not zero based they start at index 1 for readability
                 * so when creating the matrix you must subtract 1
                 *
                 *   if you have 1 row then rowsize should read 1 not 0

                 * @return
                 */
                template<typename t>
                int Perception_Element_Matrix<t>::getColumnSize() const {
                    return columnSize;
                }

                /**
                 * describe the shape of the matrix xof perception elements; rowSize and columnSize are
                 * not zero based they start at index 1 for readability
                 * so when creating the matrix you must subtract 1
                 *
                 *   if you have 1 row then rowsize should read 1 not 0

                 * @return
                 */
                template<typename t>
                void Perception_Element_Matrix<t>::setColumnSize(int columnSize) {
                    Perception_Element_Matrix::columnSize = columnSize;
                }

                template<typename t>
                void Perception_Element_Matrix<t>::setIndividualMatrixElementValue(int rowIndex, int columnIndex, float value) {
                    this->matrix[rowIndex][columnIndex].setValue(value);

                }

                template<typename t>
                Perception_Element_Matrix<t>::Perception_Element_Matrix() {}

                template<typename t>
                Perception_Element_Matrix<t>::~Perception_Element_Matrix() {

                }

                template<typename t>
                const vector<vector<t>> &Perception_Element_Matrix<t>::getMatrix() const {
                    return matrix;
                }

                template<typename t>
                void Perception_Element_Matrix<t>::setMatrix(const vector<vector<t>> &matrix) {
                    Perception_Element_Matrix::matrix = matrix;
                }

            } // Perception
        } // Network
    } // Elements
} // Matrices