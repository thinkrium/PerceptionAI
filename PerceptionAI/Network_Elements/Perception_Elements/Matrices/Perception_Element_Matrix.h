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
                    bool columnSizeIsSet;

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

                    bool operator==(const Perception_Element_Matrix &rhs) const {
                        return static_cast<const Status &>(*this) == static_cast<const Status &>(rhs) &&
                               columnSizeIsSet == rhs.columnSizeIsSet &&
                               element_matrix == rhs.element_matrix &&
                               rowSize == rhs.rowSize &&
                               columnSize == rhs.columnSize &&
                               rowSizeIsSet == rhs.rowSizeIsSet &&
                               matrixIsSet == rhs.matrixIsSet;
                    }

                    bool operator!=(const Perception_Element_Matrix &rhs) const {
                        return !(rhs == *this);
                    }

                    vector<objectName> getElementRowAt(int index) {
                        try {

                            if(
                                !
                                    (this->isMatrixIsSet()
                                    &&
                                    this->getRowSize() > index
                                    )
                            ) { throw runtime_error("nope"); }
                            return this->getElementMatrix().at(index);
                        }
                        catch (exception e) {
                            this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }

                        return this->getElementMatrix().at(index);
                    }

                    objectName getElementAt(int rowIndex, int columnIndex) {
                        try {

                            if(
                                !
                                    (this->isMatrixIsSet()
                                    &&
                                    this->getRowSize() > rowIndex
                                    &&
                                    this->getElementRowAt(rowIndex).size() > columnIndex
                                    )
                            ) { throw runtime_error("nope"); }

                            return this->element_matrix[rowIndex][columnIndex];

                        }
                        catch (exception e) {
                            this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }

                        return this->element_matrix[rowIndex][columnIndex];
                    }

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


                    Perception_Element_Matrix() {
                        this->setColumnSizeIsSet(false);
                        this->setRowSizeIsSet(false);

                        this->setMatrixIsSet(false);

                        // we dont know the size, there is no matrix to set
                        // health status - error
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(Perception_Enumerations::errorMessages::Object_Exists_But_No_Value_Set);
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
                                    )) { throw runtime_error("nope"); }

                            this->element_matrix[rowIndex][columnIndex] = element;
                        }
                        catch (exception e) {
                            cout << "error: " << e.what() << endl;
                            this->setHealthStatus(Perception_Enumerations::healthStatus::error);
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
                                throw runtime_error("nope");
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

                            transposedMatrix.setHealthStatus(Perception_Enumerations::healthStatus::ok);

                        }
                        catch (exception e) {
                            cout << "error: " << e.what();
                            transposedMatrix.setHealthStatus(Perception_Enumerations::healthStatus::error);
                        }

                        return transposedMatrix;
                    }

                    vector<vector<objectName>> &getElementMatrix()  {

                        try {

                            if(!this->isMatrixIsSet()) { throw runtime_error("nope"); }
                            return element_matrix;
                        }
                        catch (exception e) {
                           Status::setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }
                        return element_matrix;
                    }

                    void setElementMatrix(const vector<vector<objectName>> &elementMatrix) {
                        element_matrix = elementMatrix;
                        this->setMatrixIsSet(true);


                        this->setRowSize(elementMatrix.size());

                        // TODO:
                        // this assumes a square or a rectangle shape
                        // check if that has to be true
                        this->setColumnSize(elementMatrix[0].size());
                    }

                    int getRowSize() {

                        try {

                            if(!this->isRowSizeIsSet()) { throw runtime_error("nope"); }
                            return rowSize;
                        }
                        catch (exception e) {
                              this->setHealthStatus(Perception_Enumerations::healthStatus::error);

                        }
                        return rowSize;
                    }

                    void setRowSize(int rowSize) {
                        Perception_Element_Matrix::rowSize = rowSize;
                        this->setRowSizeIsSet(true);
                    }

                    int getColumnSize()  {
                        try {

                            if(!this->isColumnSizeIsSet()) { throw runtime_error("nope"); }
                            return columnSize;
                        }
                        catch (exception e) {
                          this->setHealthStatus(Perception_Enumerations::healthStatus::error);

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
