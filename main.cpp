//
// Created by thome on 1/11/2024.
//
#include "iostream"
#include "PerceptionAI/Perception_Network/Perception_Network.h"

using namespace std;
using namespace Perception::Network;

int main() {

    Perception_Network perceptionNetwork ;

    perceptionNetwork.instantiateNetwork(3, 3);

    // need to fix this
    // output nodes are kicking back an error even
    // though they should be set
    // it looks like the local nodes are set
    // so for input layer which is appropriate and what conditional do i need
//    perceptionNetwork.startNetwork();


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

    // test

    layerHelper.Prepare_Forward_Propagation_Without_Activating(previousLayer, currentLayer);

///////////////////////////////////////////////////////////////////

    return 0;
}