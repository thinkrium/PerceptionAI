//
// Created by thome on 2/4/2024.
//

#include "../../PerceptionAI/Utilities/Layer_Helper/Layer_Helper.h"
#include "gtest/gtest.h"

using namespace Perception::Network::Utilities;
// Demonstrate some basic assertions.
TEST(Layer_Helper_Test, Prepare_Forward_Propagation_Test) {

    // prepare

    Layer_Helper layerHelper;

    Layer previousLayer, currentLayer;

    int previousLayerNodeCount = 3;
    int currentLayersNodeCount = 3;

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

    // test

    layerHelper.Prepare_Forward_Propagation_Without_Activating(previousLayer, currentLayer);

}
