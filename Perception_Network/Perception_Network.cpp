//
// Created by thome on 1/13/2024.
//

#include "Perception_Network.h"

namespace Perception {
    namespace Network {

        Perception_Network::Perception_Network() {}

        Perception_Network::Perception_Network(int layerCount, int nodesPerLayer) : layer_count(layerCount),
                                                                                    nodes_per_layer(nodesPerLayer) {
            this->setLayerCount(layerCount);
            this->setNodesPerLayer(nodesPerLayer);


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

        int Perception_Network::getLayerCount() const {
            return layer_count;
        }

        void Perception_Network::setLayerCount(int layerCount) {
            layer_count = layerCount;
        }

        int Perception_Network::getNodesPerLayer() const {
            return nodes_per_layer;
        }

        void Perception_Network::setNodesPerLayer(int nodesPerLayer) {
            nodes_per_layer = nodesPerLayer;
        }

        void Perception_Network::startNetwork() {

        }

        Perception_Network::~Perception_Network() {

        }

        void Perception_Network::instantiateNetwork() {


        }
    } // Perception
} // Network