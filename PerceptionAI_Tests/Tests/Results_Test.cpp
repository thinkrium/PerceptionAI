//
// Created by thome on 3/8/2024.
//

#include "../../PerceptionAI/Network_Elements/Results/Result.h"
#include "gtest/gtest.h"

using namespace Perception::Network::Elements::Results;

TEST(Results_Test, getIndexOfOneHotEncodedTargetSetToTrue_at1) {

    Result result;
    Perception_Element_Vector<Perception_Element> oneHotEncodedTargets (3);
    vector<Perception_Element> oneHotEncodedTargetsAsRawVector = {Perception_Element(0), Perception_Element(1),Perception_Element(0)};

    oneHotEncodedTargets.setElementVector(oneHotEncodedTargetsAsRawVector);
    result.setOneHotEncodedTargets(oneHotEncodedTargets);

    int expectedIndex = 1;
    int actualIndex = result.getIndexOfOneHotEncodedTargetSetToTrue();

    EXPECT_EQ(expectedIndex, actualIndex);
}

TEST(Results_Test, getIndexOfOneHotEncodedTargetSetToTrue_at2) {

    Result result;
    Perception_Element_Vector<Perception_Element> oneHotEncodedTargets (3);
    vector<Perception_Element> oneHotEncodedTargetsAsRawVector = {Perception_Element(0), Perception_Element(0),Perception_Element(1)};

    oneHotEncodedTargets.setElementVector(oneHotEncodedTargetsAsRawVector);
    result.setOneHotEncodedTargets(oneHotEncodedTargets);

    int expectedIndex = 2;
    int actualIndex = result.getIndexOfOneHotEncodedTargetSetToTrue();

    EXPECT_EQ(expectedIndex, actualIndex);
}