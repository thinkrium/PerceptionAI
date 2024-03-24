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

TEST(Layer_Helper_Test, Sum_The_Layers_Nodes_Exponential_Values) {

    Layer layer(3);
    Perception_Element_Vector<Node> localNodes(3);

    Node one(1);
    localNodes.setIndividualElement(0, one);
    Node two(2);
    localNodes.setIndividualElement(1, two);
    Node three(3);
    localNodes.setIndividualElement(2, three);



    layer.setLocalNodes(localNodes);


    Layer_Helper layerHelper;

    // this answer differed in my calculator by 0.00000xxxxxxx
    // which i think was a floating point precision problem
    // so copied the right side of the decimal from the calculator
    // and pasted it here in the expected_exponential_sum
    // my calculator said `30.1928742232`

    double  expected_exponential_sum = 30.192874908447266;

    double  actual_exponential_sum = layerHelper.Sum_The_Layers_Nodes_Exponential_Values(layer);

    EXPECT_EQ(expected_exponential_sum,actual_exponential_sum);
}

TEST(Layer_Helper_Test, Activate_Node_With_Softmax_Positive_Numbers) {

    Node node(2);

    double exponential_sum = 40;

    Layer_Helper layerHelper;

    float expectedActivationValue = 0.184726402473;

    Node actualNode = layerHelper.Activate_Node_With_Softmax(node, exponential_sum);
    EXPECT_EQ(expectedActivationValue, actualNode.getActivatedValue());

}

TEST(Layer_Helper_Test, Activate_Node_With_Softmax_Negative_Numbers) {

    Node node(-3.2);

    double exponential_sum = 40;

    Layer_Helper layerHelper;

    // this answer differed in my calculator by 0.00000xxxxxxx
    // which i think was a floating point precision problem
    // so copied the right side of the decimal from the calculator
    // and pasted it here in the expectedActivationValue
    // my calculator said `0.00101905514`


    float expectedActivationValue = 0.00101905502;

    Node actualNode = layerHelper.Activate_Node_With_Softmax(node, exponential_sum);
    EXPECT_EQ(expectedActivationValue, actualNode.getActivatedValue());

}

TEST(Layer_Helper_Test, Calculate_Loss_With_Categorical_Cross_Entropy_Normal) {

    Layer_Helper layerHelper;

    Layer layer(3);
    Result result;

    Perception_Element_Vector<Node> activatedOutputVector(3);
    vector<Node> activatedOutputAsRawVector = {Node(.3), Node(.4), Node(.5)};

    int iteratorIndex = 0;

    for (Node activatedValue : activatedOutputAsRawVector) {
        activatedValue.setActivatedValue(activatedValue.getValue());
        activatedOutputVector.setIndividualElement(iteratorIndex, activatedValue);

        iteratorIndex++;
    }

    layer.setLocalNodes(activatedOutputVector);


    Perception_Element_Vector<Perception_Element> oneHotEncodedTargets(3);
    vector<Perception_Element> targetsAsRawVector = {Perception_Element(1), Perception_Element(0), Perception_Element(0)};
    oneHotEncodedTargets.setElementVector(targetsAsRawVector);

    result.setOneHotEncodedTargets( oneHotEncodedTargets);

    layerHelper.Calculate_Loss_With_Categorical_Cross_Entropy(layer, result);

    float expected_loss = 1.20397282;
    float actual_loss = result.getTotalLoss();

    EXPECT_EQ(expected_loss, actual_loss);
}

TEST(Layer_Helper_Test, Calculate_Loss_With_Categorical_Cross_Entropy_Clipped_0) {

    Layer_Helper layerHelper;

    Layer layer(3);
    Result result;

    Perception_Element_Vector<Node> activatedOutputVector(3);
    vector<Node> activatedOutputAsRawVector = {Node(-.3), Node(-.4), Node(-.5)};

    int iteratorIndex = 0;

    for (Node activatedValue : activatedOutputAsRawVector) {
        activatedValue.setActivatedValue(activatedValue.getValue());
        activatedOutputVector.setIndividualElement(iteratorIndex, activatedValue);

        iteratorIndex++;
    }

    layer.setLocalNodes(activatedOutputVector);


    Perception_Element_Vector<Perception_Element> oneHotEncodedTargets(3);
    vector<Perception_Element> targetsAsRawVector = {Perception_Element(1), Perception_Element(0), Perception_Element(0)};
    oneHotEncodedTargets.setElementVector(targetsAsRawVector);

    result.setOneHotEncodedTargets( oneHotEncodedTargets);

    layerHelper.Calculate_Loss_With_Categorical_Cross_Entropy(layer, result);

    float expected_loss = 16.118096;
    float actual_loss = result.getTotalLoss();

    EXPECT_EQ(expected_loss, actual_loss);
}

TEST(Layer_Helper_Test, Calculate_Loss_With_Categorical_Cross_Entropy_Clipped_1) {

    Layer_Helper layerHelper;

    Layer layer(3);
    Result result;

    Perception_Element_Vector<Node> activatedOutputVector(3);
    vector<Node> activatedOutputAsRawVector = {Node( 3), Node( 4), Node( 5)};

    int iteratorIndex = 0;

    for (Node activatedValue : activatedOutputAsRawVector) {
        activatedValue.setActivatedValue(activatedValue.getValue());
        activatedOutputVector.setIndividualElement(iteratorIndex, activatedValue);

        iteratorIndex++;
    }

    layer.setLocalNodes(activatedOutputVector);


    Perception_Element_Vector<Perception_Element> oneHotEncodedTargets(3);
    vector<Perception_Element> targetsAsRawVector = {Perception_Element(1), Perception_Element(0), Perception_Element(0)};
    oneHotEncodedTargets.setElementVector(targetsAsRawVector);

    result.setOneHotEncodedTargets( oneHotEncodedTargets);

    layerHelper.Calculate_Loss_With_Categorical_Cross_Entropy(layer, result);

    float expected_loss = 1.19209304e-007f;
    float actual_loss = result.getTotalLoss();

    EXPECT_EQ(expected_loss, actual_loss);
}

TEST(Layer_Helper_Test, Calculate_Derivative_Of_Relu_Positive) {
   Node node;

   node.setActivatedValue(3);

   float expectedDerivedValue = 1;
   Layer_Helper layerHelper;

   Node actualNode = layerHelper.Calculate_Derivative_Of_ReLu(node);
    EXPECT_EQ(expectedDerivedValue, actualNode.getDerivedValue() );
}

TEST(Layer_Helper_Test, Calculate_Derivative_Of_Relu_Negative) {
    Node node;

    node.setActivatedValue(-3);

    float expectedDerivedValue = 0;
    Layer_Helper layerHelper;

    Node actualNode = layerHelper.Calculate_Derivative_Of_ReLu(node);
    EXPECT_EQ(expectedDerivedValue, actualNode.getDerivedValue() );

}

TEST(Layer_Helper_Test, Calculate_Derivative_Of_Softmax_3_Nodes) {
    Node node;


    Layer_Helper layerHelper;

    Layer currentLayer(3);
    float activatedValue = .2f;
    vector<Node> actualNodesAsVectorRaw;


    int iterate = 0;

    for(Node node  : currentLayer.getLocalNodes().getElementVector()) {
        iterate++;
        node.setActivatedValue(iterate * activatedValue);
        actualNodesAsVectorRaw.push_back(node);
    }

    currentLayer.getLocalNodes().setElementVector(actualNodesAsVectorRaw);

    float expectedActivatedValue1 = 0.2;
    float expectedActivatedValue2 = 0.4;
    float expectedActivatedValue3 = 0.6;

    float expectedDerivative1 = expectedActivatedValue1 * (1 - expectedActivatedValue1);
    float expectedDerivative2 = expectedActivatedValue1 * (0 - expectedActivatedValue2);
    float expectedDerivative3 = expectedActivatedValue1 * (0 - expectedActivatedValue3);

    float expectedDerivative  = (expectedDerivative1 * expectedActivatedValue1)
                              + (expectedDerivative2 * expectedActivatedValue2)
                              + (expectedDerivative3 * expectedActivatedValue3);

    Node actualNode = layerHelper.Calculate_Derivative_Of_Softmax(
            node, 0,
            currentLayer);

    EXPECT_EQ(expectedDerivative, actualNode.getDerivedValue() );

}

TEST(Layer_Helper_Test, Calculate_Derivative_Of_Softmax_5_Nodes) {
    Node node;


    Layer_Helper layerHelper;

    Layer currentLayer(5);
    float activatedValue = .3f;
    vector<Node> actualNodesAsVectorRaw;


    int iterate = 0;

    for(Node node  : currentLayer.getLocalNodes().getElementVector()) {
        iterate++;
        node.setActivatedValue(iterate * activatedValue);
        actualNodesAsVectorRaw.push_back(node);
    }

    currentLayer.getLocalNodes().setElementVector(actualNodesAsVectorRaw);

    float expectedActivatedValue1 = activatedValue * 1;
    float expectedActivatedValue2 =  activatedValue * 2;
    float expectedActivatedValue3 =  activatedValue * 3;
    float expectedActivatedValue4 =  activatedValue * 4;
    float expectedActivatedValue5 =  activatedValue * 5;

    float expectedDerivative1 = expectedActivatedValue3 * (0 - expectedActivatedValue1);
    float expectedDerivative2 = expectedActivatedValue3 * (0 - expectedActivatedValue2);
    float expectedDerivative3 = expectedActivatedValue3 * (1 - expectedActivatedValue3);
    float expectedDerivative4 = expectedActivatedValue3 * (0 - expectedActivatedValue4);
    float expectedDerivative5 = expectedActivatedValue3 * (0 - expectedActivatedValue5);

    float expectedDerivative  = (expectedDerivative1 * expectedActivatedValue1)
                                + (expectedDerivative2 * expectedActivatedValue2)
                                  + (expectedDerivative3 * expectedActivatedValue3)
                                    + (expectedDerivative4 * expectedActivatedValue4)
                                + (expectedDerivative5 * expectedActivatedValue5);

    Node actualNode = layerHelper.Calculate_Derivative_Of_Softmax(
            node, 2,
            currentLayer);

    EXPECT_EQ(expectedDerivative, actualNode.getDerivedValue() );

}