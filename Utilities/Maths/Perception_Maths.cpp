//
// Created by thome on 1/13/2024.
//

#include "Perception_Maths.h"
#include "cstdlib"
#include "ctime"

namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace Maths {
                Perception_Maths::Perception_Maths() {

                }

                Perception_Maths::~Perception_Maths() {

                }

                float Perception_Maths::dotProduct(vector<float> leftVector, vector<float> rightVector) {

                    float dotProduct = 0;
                    try {
                        if (leftVector.size() != rightVector.size()) {
                            throw "The vecot";
                        }

                        for (int dotProductIndex = 0; dotProductIndex < leftVector.size(); dotProductIndex++) {
                            dotProduct += leftVector[dotProductIndex] * rightVector[dotProductIndex];
                        }
                    }
                    catch (exception e) {
                        printf(e.what());
                    }
                    return dotProduct;
                }


                vector<vector<Perception_Element>>
                Perception_Maths::dotProduct(vector<vector<Perception_Element>> leftMatrix, vector<vector<Perception_Element>> rightMatrix) {

                    // for testing dot product validity
                    int leftMatrixColumnSize = leftMatrix[0].size();
                    int rightMatrixRowSize = rightMatrix.size();

                    int leftMatrixRowSize = leftMatrix.size();
                    int rightMatrixColumnSize = rightMatrix[0].size();

                    vector<vector<Perception_Element>> dotProductMatrix (leftMatrixRowSize, vector<Perception_Element>(rightMatrixColumnSize));

                    try {
                        if (leftMatrixColumnSize != rightMatrixRowSize) { throw "nope"; }


                    }
                    catch (exception e) {
                        printf(e.what());

                    }
                    return dotProductMatrix;
                }

                vector<vector<Perception_Element>>
                Perception_Maths::invertMatrix(vector<vector<Perception_Element>> matrixToInvert) {

                    int rowSize = matrixToInvert.size();
                    int columnSize = matrixToInvert[0].size();

                    vector<vector<Perception_Element>> invertedMatrix(rowSize, vector<Perception_Element>(columnSize));

                    for(int rowIndex = 0; rowIndex < rowSize; rowIndex++) {
                        for(int columnIndex = 0 ; columnIndex < columnSize; columnIndex++) {

                            invertedMatrix[columnIndex][rowIndex] = matrixToInvert[rowIndex][columnIndex];
                        }
                    }

                    return invertedMatrix;
                }
            } // Perception
        }
    } // Utilities
} // Maths