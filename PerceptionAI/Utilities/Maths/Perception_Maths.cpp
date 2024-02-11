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
/*
 *                let left_side_row_count = left_side.length;
               let left_side_column_count = left_side[0].length;
               let result_matrix_column_count = right_side[0].length;

               for (var row_index = 0; row_index < left_side_row_count; row_index++) {

                 dot_product_result_matrix.push([]);

                  for (var matrix_column_index = 0; matrix_column_index < result_matrix_column_count; matrix_column_index++) {

                    dot_product_result_matrix[row_index][matrix_column_index] = 0;

                    for (var column_index = 0; column_index < left_side_column_count; column_index++) {

                       let left_number = left_side[row_index][column_index];
                       let right_number = right_side[column_index][matrix_column_index];
                       dot_product += left_number * right_number;
                       dot_product_result_matrix[row_index][matrix_column_index] = dot_product;
                    }

                    if(!convolution) {
                        dot_product = 0;
                    }
                 }
               }

 */
                    for(int resultMatrixColumnIndex = 0; resultMatrixColumnIndex < leftMatrixRowSize; resultMatrixColumnIndex++) {

                        vector<float> dotProductResultVector (rightMatrixColumnSize,   0);

                        for ( int inputMatrixRowIndex = 0; inputMatrixRowIndex < leftMatrixRowSize; inputMatrixRowIndex++) {


                            float individualDotProductResult = 0 ;

                            for (int inputMatrixColumnIndex = 0; inputMatrixColumnIndex < rightMatrixColumnSize; inputMatrixColumnIndex++ ) {
                                  individualDotProductResult += leftMatrix[inputMatrixRowIndex][inputMatrixRowIndex]
                                                              * rightMatrix[inputMatrixColumnIndex][inputMatrixColumnIndex];
                            }

                            dotProductResultVector[inputMatrixRowIndex] =  individualDotProductResult ;
                    }
                        dotProductMatrix[resultMatrixColumnIndex] = dotProductResultVector;
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