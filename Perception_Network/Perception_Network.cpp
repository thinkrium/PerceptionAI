//
// Created by thome on 1/13/2024.
//

#include "Perception_Network.h"

namespace Perception {
    namespace Network {

        Perception_Network::Perception_Network() {}

        Perception_Network::Perception_Network(int layerCount, int nodesPerLayer) : inner_layer_count(layerCount),
                                                                                    node_count_per_layer(nodesPerLayer) {
            this->setInnerLayerCount(layerCount);
            this->setNodeCountPerLayer(nodesPerLayer);


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
            return inner_layer_count;
        }

        void Perception_Network::setInnerLayerCount(int innerLayerCount) {
            inner_layer_count = innerLayerCount;
        }

        int Perception_Network::getNodeCountPerLayer() const {
            return node_count_per_layer;
        }

        void Perception_Network::setNodeCountPerLayer(int nodeCountPerLayer) {
            node_count_per_layer = nodeCountPerLayer;
        }

        void Perception_Network::startNetwork() {

        }

        Perception_Network::~Perception_Network() {

        }

        void Perception_Network::instantiateNetwork(int innerLayerCount, int nodeCountPerLayer) {

            this->setInnerLayerCount(innerLayerCount);
            this->setNodeCountPerLayer(nodeCountPerLayer);

            this->setInputLayer();
            this->setInnerLayers();
            this->setOutputLayer();

        }

        void Perception_Network::setInnerLayers() {

            if(
                this->getInnerLayerCount() == 0
                ||
                this->getNodeCountPerLayer() == 0
                ) {
                return;
            }


            this->setInnerLayers(  vector< Layer>(this->getInnerLayerCount()));

            for (int index = 0; index < this->getInnerLayerCount(); index++) {

                this->innerLayers[index] = Layer(this->getNodeCountPerLayer());

                if(index == 0) {
                    // this is the input layer
                    this->innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards( 3 );
                }
                else {
                    this->innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards(
                        this->innerLayers[index - 1].getNodeCountPerLayer()
                    );
                }

                this->innerLayers[index].initiateAllLocalNodesWithRandomValues();
                this->innerLayers[index].initiateAllWeightsWithRandomValues();
                this->innerLayers[index].initiateAllBiasesWithRandomValues();



            }

        }

        void Perception_Network::setInputLayer() {
            Layer inputLayer(3);

            vector<Node> inputs(3);

            for(int ind; ind < 3; ind++) {
                inputs[ind].setValue(ind + 1);
            }

            inputLayer.setLocalNodes(inputs);

            this->setInputLayer(inputLayer);
        }

        void Perception_Network::setOutputLayer() {
            Layer outputLayer(3);

            outputLayer.setNodeCountPerPreviousLayerGoingPropagatingForwards(3);
            outputLayer.initiateAllLocalNodesWithRandomValues();
            outputLayer.initiateAllBiasesWithRandomValues();
            outputLayer.initiateAllWeightsWithRandomValues();


            this->setOutputLayer(outputLayer);
        }
    } // Perception
} // Network