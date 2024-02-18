//
// Created by thome on 2/4/2024.
//

#include "../../PerceptionAI/Utilities/Layer_Helper/Layer_Helper.h"
#include "gtest/gtest.h"

using namespace Perception::Network::Utilities;
// Demonstrate some basic assertions.
TEST(Layer_Helper_Test, Prepare_Forward_Propagation_Test_3_Nodes) {



///////////////////////////////////////////////////////////////////

    Layer_Helper layerHelper;


    int previousLayerNodeCount = 3;
    int currentLayersNodeCount = 3;

    Layer previousLayer(previousLayerNodeCount), currentLayer(currentLayersNodeCount);

    Perception_Element_Vector<Node> previousOutputsNodeVector;

    Perception_Element_Matrix<Weight> currentLayersWeightsMatrix;

    vector<Node> previousOutputNodes (previousLayerNodeCount);

    vector<vector<Weight>> currentLayersWeights(previousLayerNodeCount, vector<Weight>(currentLayersNodeCount));

    // set output nodes
    for(int i = 0; i < previousLayerNodeCount; i++) {
        Node node;
        node.setValue((float)(i + 1));

        previousOutputNodes.at(i) = node;
    }

    // set weights
    for(int i = 0; i < currentLayersNodeCount; i++) {
        for(int j = 0; j < currentLayersNodeCount; j++) {
            Weight weight;

            weight.setValue((float)(j + 1));

            currentLayersWeights[i][j] = weight;
        }
    }

    previousOutputsNodeVector.setElementVector(previousOutputNodes);

    currentLayersWeightsMatrix.setElementMatrix(currentLayersWeights);

    previousOutputsNodeVector.setHealthStatus(Enumerations::Perception_Enumerations::healthStatus::ok);

    currentLayersWeightsMatrix.setHealthStatus(Enumerations::Perception_Enumerations::healthStatus::ok);

    previousLayer.setOutputNodes(previousOutputsNodeVector);

    currentLayer.setWeights(currentLayersWeightsMatrix);

    // assert
    Perception_Element_Vector<Node> expectedValue;

    vector<Node> values = {Node(14),Node(14),Node(14)};

    expectedValue.setElementVector(values);
    // test

    layerHelper.Prepare_Forward_Propagation_Without_Activating(previousLayer, currentLayer);

    Perception_Element_Vector<Node> actualValue = currentLayer.getLocalNodes();
    bool valuesAreEqual = true;

    for(int i = 0; i < currentLayersNodeCount; i++) {
        if (
                expectedValue.getElementAt(i).getValue()
                !=
                actualValue.getElementAt(i).getValue()
                ) {
            valuesAreEqual = false;
        }
    }

    ///////////////////////////////////////////////////////////////////

    EXPECT_TRUE(valuesAreEqual);
}

TEST(Layer_Helper_Test, Prepare_Forward_Propagation_Test_4_Nodes) {



///////////////////////////////////////////////////////////////////

    Layer_Helper layerHelper;


    int previousLayerNodeCount = 4;
    int currentLayersNodeCount = 4;

    Layer previousLayer(previousLayerNodeCount), currentLayer(currentLayersNodeCount);

    Perception_Element_Vector<Node> previousOutputsNodeVector;

    Perception_Element_Matrix<Weight> currentLayersWeightsMatrix;

    vector<Node> previousOutputNodes (previousLayerNodeCount);

    vector<vector<Weight>> currentLayersWeights(previousLayerNodeCount, vector<Weight>(currentLayersNodeCount));

    // set output nodes
    for(int i = 0; i < previousLayerNodeCount; i++) {
        Node node;
        node.setValue((float)(i + 1));

        previousOutputNodes.at(i) = node;
    }

    // set weights
    for(int i = 0; i < currentLayersNodeCount; i++) {
        for(int j = 0; j < currentLayersNodeCount; j++) {
            Weight weight;

            weight.setValue((float)(j + 1));

            currentLayersWeights[i][j] = weight;
        }
    }

    previousOutputsNodeVector.setElementVector(previousOutputNodes);

    currentLayersWeightsMatrix.setElementMatrix(currentLayersWeights);

    previousOutputsNodeVector.setHealthStatus(Enumerations::Perception_Enumerations::healthStatus::ok);

    currentLayersWeightsMatrix.setHealthStatus(Enumerations::Perception_Enumerations::healthStatus::ok);

    previousLayer.setOutputNodes(previousOutputsNodeVector);

    currentLayer.setWeights(currentLayersWeightsMatrix);

    // assert
    Perception_Element_Vector<Node> expectedValue;

    vector<Node> values = {Node(30),Node(30),Node(30),Node(30)};

    expectedValue.setElementVector(values);
    // test

    layerHelper.Prepare_Forward_Propagation_Without_Activating(previousLayer, currentLayer);

    Perception_Element_Vector<Node> actualValue = currentLayer.getLocalNodes();
    bool valuesAreEqual = true;

    for(int i = 0; i < currentLayersNodeCount; i++) {
        if (
                expectedValue.getElementAt(i).getValue()
                !=
                actualValue.getElementAt(i).getValue()
                ) {
            valuesAreEqual = false;
        }
    }

    ///////////////////////////////////////////////////////////////////

    EXPECT_TRUE(valuesAreEqual);
}

TEST(Layer_Helper_Test, Activate_Nodes_With_Relu_Positive_Numbers) {


    Layer_Helper layerHelper;

    Layer layer(3);

    int nodeCount = 3;
    Perception_Element_Vector<Node> nodeVector(nodeCount);

    vector <Node> expectedNodes = {Node(3), Node(3), Node(3) };

    nodeVector.setElementVector(expectedNodes);

    layer.setLocalNodes(nodeVector);

    layerHelper.Activate_Nodes_With_ReLU(layer);

    float expectedValue = 3;

    Perception_Element_Vector<Node> actualValueVector = layer.getLocalNodes();

    vector<Node> actualNodes = actualValueVector.getElementVector();


    ///////////////////////////////////////////////////////////////////

    EXPECT_EQ(expectedNodes, actualNodes);

}

TEST(Layer_Helper_Test, Activate_Nodes_With_Relu_Negative_Numbers) {

    Layer_Helper layerHelper;

    Layer layer(3);

    int nodeCount = 3;
    Perception_Element_Vector<Node> nodeVector(nodeCount);

    vector <Node> expectedNodes = {Node(-3), Node(-3), Node(-3) };

    nodeVector.setElementVector(expectedNodes);

    layer.setLocalNodes(nodeVector);

    layerHelper.Activate_Nodes_With_ReLU(layer);

    float expectedValue = 0;

     Perception_Element_Vector<Node> actualValueVector = layer.getLocalNodes();

    vector<Node> actualNodes = actualValueVector.getElementVector();


    ///////////////////////////////////////////////////////////////////

    EXPECT_EQ(expectedNodes, actualNodes);

}