//
// Created by thome on 1/13/2024.
//

#include "Perception_Network.h"

namespace Perception {
    namespace Network {

        Perception_Network::Perception_Network() {}

        Perception_Network::Perception_Network(int layerCount, int nodesPerLayer) : innerLayerCount(layerCount),
                                                                                    nodeCountPerInnerLayer(nodesPerLayer) {
            this->setInnerLayerCount(layerCount);
            this->setNodeCountPerInnerLayer(nodesPerLayer);


        }

        const Layer &Perception_Network::getInputLayer() const {
            return inputLayer;
        }

        void Perception_Network::setInputLayer(const Layer &inputLayer) {
            Perception_Network::inputLayer = inputLayer;
        }

        const vector<Layer> &Perception_Network::getInnerLayers() const {
            return innerLayers;
        }

        void Perception_Network::setInnerLayers(const vector<Layer> &innerLayers) {
            Perception_Network::innerLayers = innerLayers;
        }

        const Layer &Perception_Network::getOutputLayer() const {
            return outputLayer;
        }

        void Perception_Network::setOutputLayer(const Layer &outputLayer) {
            Perception_Network::outputLayer = outputLayer;
        }

        int Perception_Network::getInnerLayerCount() const {
            return innerLayerCount;
        }

        void Perception_Network::setInnerLayerCount(int innerLayerCount) {
            innerLayerCount = innerLayerCount;
        }

        int Perception_Network::getNodeCountPerInnerLayer() const {
            return nodeCountPerInnerLayer;
        }

        void Perception_Network::setNodeCountPerInnerLayer(int nodeCountPerLayer) {
            nodeCountPerInnerLayer = nodeCountPerLayer;
        }

        void Perception_Network::startNetwork() {

        }

        Perception_Network::~Perception_Network() {

        }

        void Perception_Network::instantiateNetwork(int innerLayerCount, int nodeCountPerLayer) {

            this->setInnerLayerCount(innerLayerCount);
            this->setNodeCountPerInnerLayer(nodeCountPerLayer);

            this->setInputLayer();
            this->setInnerLayers();
            this->setOutputLayer();

        }

        void Perception_Network::setInnerLayers() {

            if(
                this->getInnerLayerCount() == 0
                ||
                        this->getNodeCountPerInnerLayer() == 0
                ) {
                return;
            }


            this->setInnerLayers(  vector< Layer>(this->getInnerLayerCount()));

            for (int index = 0; index < this->getInnerLayerCount(); index++) {

                this->innerLayers[index] = Layer(this->getNodeCountPerInnerLayer());

                if(index == 0) {
                    // this is the input layer
                    this->innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards( 3 );
                }
                else {
                    this->innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards(
                        this->innerLayers[index - 1].getNodeCountPerLayer()
                    );
                }

//                this->innerLayers[index].initiateAllLocalNodesWithRandomValues();
//                this->innerLayers[index].initiateAllWeightsWithRandomValues();
//                this->innerLayers[index].initiateAllBiasesWithRandomValues();



            }

        }

        void Perception_Network::setInputLayer() {

            if(this->getNodeCountPerInnerLayer() == 0) return;

            Layer inputLayer(this->getNodeCountPerInnerLayer());

            vector<Node> inputs(this->getNodeCountPerInnerLayer());

            for(int nodeCountIndex = 0; nodeCountIndex < this->getNodeCountPerInnerLayer(); nodeCountIndex++) {
                inputs[nodeCountIndex].setValue(nodeCountIndex + 1);
            }

            inputLayer.setLocalNodes(inputs);

            this->setInputLayer(inputLayer);
        }

        void Perception_Network::setOutputLayer() {
            Layer outputLayer(3);

            vector<Node> localNodes(3);
            outputLayer.setNodeCountPerPreviousLayerGoingPropagatingForwards(3);


            this->setOutputLayer(outputLayer);
        }

        int Perception_Network::getInputLayerNodeCount() const {
            return inputLayerNodeCount;
        }

        void Perception_Network::setInputLayerNodeCount(int inputLayerNodeCount) {
            Perception_Network::inputLayerNodeCount = inputLayerNodeCount;
        }

        int Perception_Network::getOutputLayerNodeCount() const {
            return outputLayerNodeCount;
        }

        void Perception_Network::setOutputLayerNodeCount(int outputLayerNodeCount) {
            Perception_Network::outputLayerNodeCount = outputLayerNodeCount;
        }
    } // Perception
} // Network