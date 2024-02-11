//
// Created by thome on 2/4/2024.
//

#include "../../PerceptionAI/Utilities/Maths/Perception_Maths.h"
#include "gtest/gtest.h"

using namespace Perception::Network::Utilities::Maths;
// Demonstrate some basic assertions.
TEST(Layer_Helper_Test, VectorDotProductTest) {

    // prepare

    Perception_Maths perceptionMaths;

    vector<float> left {1,2,3};
    vector<float> right  {3,4,5};

    float expected_result = 26;

    // assert

    float actual_result = perceptionMaths.dotProduct(left,right);
    // test

    EXPECT_EQ(expected_result, actual_result);



}

TEST(Layer_Helper_Test, MatrixDotProductTest) {

    // prepare

    Perception_Maths perceptionMaths;

    vector<vector<float>> left {
                                 {1,2,3}
                                ,{1,2,3}
                                ,{1,2,3}
                               };

    vector<vector<float>> right {
                                 {1,2,3}
                                ,{1,2,3}
                                ,{1,2,3}
                                };

    vector<vector<float>> expected_result {
                                 {6,12,18}
                                ,{6,12,18}
                                ,{6,12,18}
                                };

    // assert

    vector<vector<float>> actual_result = perceptionMaths.dotProduct(left,right);
    // test

    EXPECT_EQ(expected_result, actual_result);



}

