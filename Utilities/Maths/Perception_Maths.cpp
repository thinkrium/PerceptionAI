//
// Created by thome on 1/13/2024.
//

#include "Perception_Maths.h"

namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace Maths {
                Perception_Maths::Perception_Maths() {

                }

                Perception_Maths::~Perception_Maths() {

                }


                template<typename t> Perception_Element_Matrix<t>
                Perception_Maths::dotProduct(
                        Perception_Element_Matrix<t> leftMatrix,
                        Perception_Element_Matrix<t> rightMatrix) {

                    // for testing dot product validity
                    int leftMatrixColumnSize = leftMatrix.getMatrix()[0].size();
                    int rightMatrixRowSize = rightMatrix.getMatrix().size();

                    int leftMatrixRowSize = leftMatrix.getMatrix().size();
                    int rightMatrixColumnSize = rightMatrix.getMatrix()[0].size();

                    // you have to add 1 to the index size because for readability they are not zero indexed
                    // hovering over the function name will reveal the tool tip
                    Perception_Element_Matrix<t> dotProductMatrix((leftMatrixRowSize + 1), (rightMatrixColumnSize + 1) );

                    try {
                        if (leftMatrixColumnSize != rightMatrixRowSize) { throw "nope"; }


                    }
                    catch (exception e) {
                        printf(e.what());

                    }
                    return dotProductMatrix;
                }

                template<typename t> Perception_Element_Matrix<t>
                Perception_Maths::invertMatrix(Perception_Element_Matrix<t> matrixToInvert) {

                    int rowSize = matrixToInvert.getMatrix().size();
                    int columnSize = matrixToInvert.getMatrix()[0].size();

                    // you have to add 1 to the index size because for readability they are not zero indexed
                    // hovering over the function name will reveal the tool tip
                    Perception_Element_Matrix<t> invertedMatrix((rowSize + 1) , (columnSize + 1));

                    for(int rowIndex = 0; rowIndex < rowSize; rowIndex++) {
                        for(int columnIndex = 0 ; columnIndex < columnSize; columnIndex++) {

                            invertedMatrix.setIndividualMatrixElementValue(columnIndex,
                                                                           rowIndex,
                                                                           matrixToInvert.getMatrix()[rowIndex][columnIndex]);
                        }
                    }

                    return invertedMatrix;
                }
            } // Perception
        }
    } // Utilities
} // Maths