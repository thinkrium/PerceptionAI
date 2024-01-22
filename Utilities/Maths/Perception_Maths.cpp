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


                Perception_Element_Matrix  Perception_Maths::dotProduct(
                        Perception_Element_Matrix leftMatrix,
                        Perception_Element_Matrix rightMatrix) {

                    // for testing dot product validity
                    int leftMatrixColumnSize = leftMatrix.getMatrix()[0].size();
                    int rightMatrixRowSize = rightMatrix.getMatrix().size();

                    int leftMatrixRowSize = leftMatrix.getMatrix().size();
                    int rightMatrixColumnSize = rightMatrix.getMatrix()[0].size();

                    // you have to add 1 to the index size because for readability they are not zero indexed
                    // hovering over the function name will reveal the tool tip
                    Perception_Element_Matrix dotProductMatrix((leftMatrixRowSize + 1), (rightMatrixColumnSize + 1) );

                    try {
                        if (leftMatrixColumnSize != rightMatrixRowSize) { throw "nope"; }


                        for(int resultMatrixColumnIndex = 0; resultMatrixColumnIndex < leftMatrixRowSize; resultMatrixColumnIndex++) {

                            float individualDotProductResult = 0;

                            for ( int inputMatrixRowIndex = 0; inputMatrixRowIndex < leftMatrixRowSize; inputMatrixRowIndex++) {
                                for (int inputMatrixColumnIndex = 0; inputMatrixColumnIndex < rightMatrixColumnSize; inputMatrixColumnIndex++ ) {
                                      individualDotProductResult += leftMatrix.getMatrix()[inputMatrixRowIndex][inputMatrixColumnIndex].getValue()
                                                                  * rightMatrix.getMatrix()[inputMatrixRowIndex][inputMatrixColumnIndex].getValue();
                                }

                                Perception_Element element(individualDotProductResult);
                                dotProductMatrix.setIndividualMatrixElement(
                                        inputMatrixRowIndex,
                                        resultMatrixColumnIndex,
                                        element);
                            }
                        }

                    }
                    catch (exception e) {
                        printf(e.what());

                    }
                    return dotProductMatrix;
                }

            } // Perception
        }
    } // Utilities
} // Maths