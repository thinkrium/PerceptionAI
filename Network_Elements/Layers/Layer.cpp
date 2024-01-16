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
            return this->inputNodes;
        }

        void Layer::setInputNodes(const vector<Node> &inputNodes) {
            this->inputNodes = inputNodes;
        }

        const vector<Node> &Layer::getLocalNodes() const {
            return this->localNodes;
        }

        void Layer::setLocalNodes(const vector<Node> &localNodes) {
            this->localNodes = localNodes;
        }

        const vector<Node> &Layer::getOutputNodes() const {
            return this->outputNodes;
        }

        void Layer::setOutputNodes(const vector<Node> &outputNodes) {
            this->outputNodes = outputNodes;
        }

        const vector<vector<Weight>> &Layer::getWeights() const {
            return this->weights;
        }

        void Layer::setWeights(const vector<vector<Weight>> &weights) {
            this->weights = weights;
        }

        const vector<Bias> &Layer::getBiases() const {
            return this->biases;
        }

        void Layer::setBiases(const vector<Bias> &biases) {
            this->biases = biases;
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
            return this->nodeCountPerLayer;
        }

        void Layer::setNodeCountPerLayer(int nodesPerLayer) {
            this->nodeCountPerLayer = nodesPerLayer;
        }


        int Layer::getNodeCountPerPreviousLayerGoingPropagatingForwards() const {
            return this->nodeCountPerPreviousLayerGoingPropagatingForwards;
        }

        void Layer::setNodeCountPerPreviousLayerGoingPropagatingForwards(
                int nodeCountPerPreviousLayerGoingPropagatingForwards) {
            this->nodeCountPerPreviousLayerGoingPropagatingForwards = nodeCountPerPreviousLayerGoingPropagatingForwards;
        }


    } // Perception
} // Layers