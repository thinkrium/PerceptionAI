//
// Created by thome on 1/11/2024.
//

#include "Layer.h"


namespace Perception {
    namespace Layers {
        Layer::Layer() {

            this->setNodeCountPerLayer(0);
        }

        Layer::~Layer() = default;

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

        /***
         * sending in this parameter does not set the actual nodes per layer
         * only the parameter nodeCountPerLayer for use later
         * @param nodesPerLayer
         */
        Layer::Layer(int nodesPerLayer) : nodeCountPerLayer(nodesPerLayer) {
            this->setNodeCountPerLayer(nodesPerLayer);

        }

        int Layer::getNodeCountPerLayer() const {
            return nodeCountPerLayer;
        }

        void Layer::setNodeCountPerLayer(int nodesPerLayer) {
            Layer::nodeCountPerLayer = nodesPerLayer;
        }


        int Layer::getNodeCountPerPreviousLayerGoingPropagatingForwards() const {
            return nodeCountPerPreviousLayerGoingPropagatingForwards;
        }

        void Layer::setNodeCountPerPreviousLayerGoingPropagatingForwards(
                int nodeCountPerPreviousLayerGoingPropagatingForwards) {
            Layer::nodeCountPerPreviousLayerGoingPropagatingForwards = nodeCountPerPreviousLayerGoingPropagatingForwards;
        }


    } // Perception
} // Layers