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
                /**
                 * the parameter is sent in and if
                 *
                 * it is larger than 1 - 1e-7 than it = 1 - 1e-7
                 * or if it is smaller than 1e-7 then it equals 1e-7
                 * ::
                 * 1e-7 = .0000001;
                 * 1-1e-7 = .9999999
                 * @param value
                 * @returns {number}
                 * @constructor
                 */
                float Perception_Maths::Clip_Value(float value) {
                    if (value <= 0) {
                        value = 0.0000001;
                    }
                    else if (value >= 1) {
                        value = .9999999;
                    }

                    return value;
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