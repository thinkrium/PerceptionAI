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


                vector<vector<float>> Perception_Maths::dotProduct(
                        vector<vector<float>> leftMatrix,
                        vector<vector<float>> rightMatrix) noexcept {

                    // for testing dot product validity
                    int leftMatrixColumnSize = leftMatrix[0].size();
                    int rightMatrixRowSize = rightMatrix.size();

                    int leftMatrixRowSize = leftMatrix.size();
                    int rightMatrixColumnSize = rightMatrix[0].size();

                    // you have to add 1 to the index size because for readability they are not zero indexed
                    // hovering over the function name will reveal the tool tip

                     vector<vector<float>> dotProductMatrix((leftMatrixRowSize + 1), vector<float> (rightMatrixColumnSize + 1) );
                     for(int resultMatrixColumnIndex = 0; resultMatrixColumnIndex < leftMatrixRowSize; resultMatrixColumnIndex++) {

                         float individualDotProductResult = 0 ;
                         vector<float> dotProductResultVector (rightMatrixColumnSize,   0);

                        for ( int inputMatrixRowIndex = 0; inputMatrixRowIndex < leftMatrixRowSize; inputMatrixRowIndex++) {
                            for (int inputMatrixColumnIndex = 0; inputMatrixColumnIndex < rightMatrixColumnSize; inputMatrixColumnIndex++ ) {
                                  individualDotProductResult += leftMatrix[inputMatrixRowIndex][inputMatrixColumnIndex]
                                                              * rightMatrix[inputMatrixRowIndex][inputMatrixColumnIndex];
                            }

                            dotProductResultVector.push_back(individualDotProductResult);
                        }
                        dotProductMatrix.push_back(dotProductResultVector);
                    }

                     return dotProductMatrix;
                }


                float Perception_Maths::dotProduct(vector<float> leftVector,
                                                   vector<float> rightVector) {


                        float dotProductResult = 0;

                        for (int index = 0; index < leftVector.size(); index++) {

                            dotProductResult += leftVector[index]
                                             *  rightVector[index];
                        }


                     return dotProductResult;
                }

            } // Perception
        }
    } // Utilities
} // Maths