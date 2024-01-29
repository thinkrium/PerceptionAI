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

                template <typename objectName>
                class Perception_Element_Matrix : public Status {
                private:
                    vector<vector<objectName>> element_matrix;

                    int rowSize;

                    int columnSize;

                    bool rowSizeIsSet;

                    bool matrixIsSet;
                public:
                    bool isMatrixIsSet() const {
                        return matrixIsSet;
                    }

                    void setMatrixIsSet(bool matrixIsSet) {
                        Perception_Element_Matrix::matrixIsSet = matrixIsSet;
                    }

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

                        this->setMatrixIsSet(false);

                        // we dont know the size, there is no matrix to set
                        // health status - error
//                        //this->setHealthStatus(Perception_Enumerations::healthStatus::error)
                    }

                    void setIndividualElement(int rowIndex, int columnIndex, objectName element) {
                        try {
                            if(
                                !(
                                    this->rowSizeIsSet()
                                    &&
                                    this->columnSizeIsSet()
                                    &&
                                    this->isMatrixIsSet()
                                    )) { throw "nope"; }

                            this->element_matrix[rowIndex][columnIndex] = element;
                        }
                        catch (exception e) {
                            cout << "error: " << e.what() << endl;
//                            //this->setHealthStatus(Perception_Enumerations::healthStatus::error)
                        }
                    }

                    ~Perception_Element_Matrix() override {

                    }

                    Perception_Element_Matrix(int rowSize, int columnSize) : rowSize(rowSize), columnSize(columnSize) {


                        this->setRowSize(rowSize);

                        this->setColumnSize(columnSize);

                        this->setElementMatrix(vector<vector<objectName>>(
                                this->getRowSize(),
                                vector<objectName>(this->getColumnSize())
                                ));

                        this->setMatrixIsSet(true);

                        this->setHealthStatus(Perception_Enumerations::healthStatus::ok);
                    }

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

//                            transposedMatrix.setHealthStatus(Perception_Enumerations::healthStatus::ok);

                        }
                        catch (exception e) {
                            cout << "error: " << e.what();
//                            transposedMatrix.setHealthStatus(Perception_Enumerations::healthStatus::error);
                        }

                        return transposedMatrix;
                    }

                    const vector<vector<objectName>> &getElementMatrix() const {

                        try {

                            if(!this->isMatrixIsSet()) { throw "nope"; }
                            return element_matrix;
                        }
                        catch (exception e) {
//                           Status::setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }
                        return element_matrix;
                    }

                    void setElementMatrix(const vector<vector<objectName>> &elementMatrix) {
                        element_matrix = elementMatrix;
                        this->setMatrixIsSet(true);
                    }

                    int getRowSize() const {

                        try {

                            if(!this->isRowSizeIsSet()) { throw "nope"; }
                            return rowSize;
                        }
                        catch (exception e) {
//                              //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

                        }
                        return rowSize;
                    }

                    void setRowSize(int rowSize) {
                        Perception_Element_Matrix::rowSize = rowSize;
                        this->setRowSizeIsSet(true);
                    }

                    int getColumnSize() const {
                        try {

                            if(!this->isColumnSizeIsSet()) { throw "nope"; }
                            return columnSize;
                        }
                        catch (exception e) {
//                          this->setHealthStatus(Perception_Enumerations::healthStatus::error);
//
                        }

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
