//
// Created by thome on 1/11/2024.
//

#include "Layer.h"

namespace Perception {
    namespace Layers {
        Layer::Layer() {}

        Layer::~Layer() {

        }

        const vector<Node> &Layer::getInputNodes() const {
            return inputNodes;
        }

        void Layer::setInputNodes(const vector<Node> &inputNodes) {
            Layer::inputNodes = inputNodes;
        }

        const vector<Node> &Layer::getLocalNodes() const {
            return localNodes;
        }

        void Layer::setLocalNodes(const vector<Node> &localNodes) {
            Layer::localNodes = localNodes;
        }

        const vector<Node> &Layer::getOutputNodes() const {
            return outputNodes;
        }

        void Layer::setOutputNodes(const vector<Node> &outputNodes) {
            Layer::outputNodes = outputNodes;
        }

        const vector<vector<Weight>> &Layer::getWeights() const {
            return weights;
        }

        void Layer::setWeights(const vector<vector<Weight>> &weights) {
            Layer::weights = weights;
        }

        const vector<Bias> &Layer::getBiases() const {
            return biases;
        }

        void Layer::setBiases(const vector<Bias> &biases) {
            Layer::biases = biases;
        }

        Layer::Layer(int nodesPerLayer) : nodesPerLayer(nodesPerLayer) {
            this->setNodesPerLayer(nodesPerLayer);

        }

        int Layer::getNodesPerLayer() const {
            return nodesPerLayer;
        }

        void Layer::setNodesPerLayer(int nodesPerLayer) {
            Layer::nodesPerLayer = nodesPerLayer;
        }
    } // Perception
} // Layers