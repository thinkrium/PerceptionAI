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

                    vector<vector<float>> dotProductMatrix((leftMatrixRowSize), vector<float> (rightMatrixColumnSize) );

                    for(int leftMatrixRowIndex = 0; leftMatrixRowIndex < leftMatrixRowSize; leftMatrixRowIndex++) {

                        vector<float> dotProductResultVector (rightMatrixColumnSize,   0);
                        for (int rightMatrixColumnIndex = 0; rightMatrixColumnIndex < rightMatrixColumnSize; rightMatrixColumnIndex++) {
                            float individualDotProductResult = 0 ;
                            for (int leftMatrixColumnIndex = 0; leftMatrixColumnIndex < leftMatrixColumnSize; leftMatrixColumnIndex++ ) {
                                  individualDotProductResult += leftMatrix[leftMatrixRowIndex][leftMatrixColumnIndex]
                                                              * rightMatrix[leftMatrixColumnIndex][rightMatrixColumnIndex];
                            }

                            dotProductResultVector[rightMatrixColumnIndex] =  individualDotProductResult ;
                    }
                        dotProductMatrix[leftMatrixRowIndex] = dotProductResultVector;
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