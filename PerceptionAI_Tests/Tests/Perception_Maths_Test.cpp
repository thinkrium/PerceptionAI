//
// Created by thome on 2/4/2024.
//

#include "../../PerceptionAI/Utilities/Maths/Perception_Maths.h"
#include "gtest/gtest.h"

using namespace Perception::Network::Utilities::Maths;
// Demonstrate some basic assertions.
TEST(Perception_Maths_Test, VectorDotProductTest) {

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

TEST(Perception_Maths_Test, MatrixDotProductTest3x3) {

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

TEST(Perception_Maths_Test, MatrixDotProductTest4x4) {

    // prepare

    Perception_Maths perceptionMaths;

    vector<vector<float>> left {
             {2,  2,  4, 4}
            ,{3, -3, 13, 1}
            ,{4,  2,  3, 8}
            ,{5, -2,  3, 7}
    };

    vector<vector<float>> right {
             {2,  2,  4, 4}
            ,{3, -3, 13, 1}
            ,{4,  2,  3, 8}
            ,{5, -2,  3, 7}
    };

    vector<vector<float>> expected_result {
             {46	,-2,	58,	70}
            ,{54,	39	,15,	120}
            ,{66,	-8,	75,	98}
            ,{51,	8	,24,	91}
    };

    // assert

    vector<vector<float>> actual_result = perceptionMaths.dotProduct(left,right);
    // test

    EXPECT_EQ(expected_result, actual_result);



}

