//
// Created by thome on 1/19/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H
#define PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H

#include "../Individual/Perception_Element.h"
#include "../../Statuses/Status.h"

#include "vector"

#include "iostream"

using namespace std;

using namespace Perception::Network::Elements::Statuses;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Matrices {

                template <class objectName>
                class Perception_Element_Matrix : public Status {
                private:
                    vector<vector<objectName>> element_matrix;

                    int rowSize;

                    int columnSize;

                    bool rowSizeIsSet;
                public:
                    bool isRowSizeIsSet() const {
                        return rowSizeIsSet;
                    }

                    void setRowSizeIsSet(bool rowSizeIsSet) {
                        Perception_Element_Matrix::rowSizeIsSet = rowSizeIsSet;
                    }

                    bool isColumnSizeIsSet() const {
                        return columnSizeIsSet;
                    }

                    void setColumnSizeIsSet(bool columnSizeIsSet) {
                        Perception_Element_Matrix::columnSizeIsSet = columnSizeIsSet;

                    }

                private:
                    bool columnSizeIsSet;

                public:

                    Perception_Element_Matrix() {
                        this->setColumnSizeIsSet(false);
                        this->setRowSizeIsSet(false);

                        // i might want to assume poor health ... not sure yet
                        // for now i will assume health ok
                        this->setHealthStatus(Perception_Enumerations::healthStatus::ok);
                    }

                    void setIndividualElement(int rowIndex, int columnIndex, objectName element) {
                        try {
                            if( !(this->rowSizeIsSet() && this->columnSizeIsSet())) { throw "nope"; }

                            this->element_matrix[rowIndex][columnIndex] = element;
                        }
                        catch (exception e) {
                            cout << "error: " << e.what() << endl;
                        }
                    }

                    ~Perception_Element_Matrix() override {

                    }

                    Perception_Element_Matrix(int rowSize, int columnSize) : rowSize(rowSize), columnSize(columnSize) {}

                    Perception_Element_Matrix transpose(Perception_Element_Matrix matrixToTranspose) {


                        Perception_Element_Matrix transposedMatrix;

                        try {

                            if(
                                !(matrixToTranspose.rowSizeIsSet()
                                &&
                                matrixToTranspose.columnSizeIsSet())
                               ) {
                                throw "nope";
                            }

                            int rowSize = matrixToTranspose.getMatrix().size();
                            int columnSize = matrixToTranspose.getMatrix()[0].size();

                            // you have to add 1 to the index size because for readability they are not zero indexed
                            // hovering over the function name will reveal the tool tip
                            transposedMatrix.setRowSize(rowSize + 1);
                            transposedMatrix.setColumnSize(columnSize + 1);

                            for (int rowIndex = 0; rowIndex < rowSize; rowIndex++) {
                                for (int columnIndex = 0; columnIndex < columnSize; columnIndex++) {

                                    transposedMatrix.setIndividualElement(columnIndex,
                                                                          rowIndex,
                                                                          matrixToTranspose.getMatrix()[rowIndex][columnIndex]);
                                }
                            }
                        }
                        catch (exception e) {
                            cout << "error: " << e.what();
                            transposedMatrix.setHealthStatus(Perception_Enumerations::healthStatus::error);
                        }

                        return transposedMatrix;
                    }

                    const vector<vector<objectName>> &getElementMatrix() const {
                        return element_matrix;
                    }

                    void setElementMatrix(const vector<vector<objectName>> &elementMatrix) {
                        element_matrix = elementMatrix;
                    }

                    int getRowSize() const {
                        return rowSize;
                    }

                    void setRowSize(int rowSize) {
                        Perception_Element_Matrix::rowSize = rowSize;
                        this->setRowSizeIsSet(true);
                    }

                    int getColumnSize() const {
                        return columnSize;
                    }

                    void setColumnSize(int columnSize) {
                        Perception_Element_Matrix::columnSize = columnSize;
                        this->setColumnSizeIsSet(true);
                    }


                };

            } // Perception
        } // Network
    } // Elements
} // Matrices

#endif //PERCEPTIONAI_PERCEPTION_ELEMENT_MATRIX_H
