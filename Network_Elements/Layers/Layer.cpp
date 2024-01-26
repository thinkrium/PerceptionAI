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

        const Perception_Element_Vector<Node> &Layer::getInputNodes() const {
            return this->inputNodes;
        }


        void Layer::setInputNodes(const Perception_Element_Vector<Node> &inputNodes) {
            Layer::inputNodes = inputNodes;
        }

        const Perception_Element_Vector<Node> &Layer::getLocalNodes() const {
            return localNodes;
        }

        void Layer::setLocalNodes(const Perception_Element_Vector<Node> &localNodes) {
            Layer::localNodes = localNodes;
        }

        const Perception_Element_Vector<Node> &Layer::getOutputNodes() const {
            return outputNodes;
        }

        void Layer::setOutputNodes(const Perception_Element_Vector<Node> &outputNodes) {
            Layer::outputNodes = outputNodes;
        }

        const Perception_Element_Vector<Bias> &Layer::getBiases() const {
            return biases;
        }

        void Layer::setBiases(const Perception_Element_Vector<Bias> &biases) {
            Layer::biases = biases;
        }

        const Perception_Element_Matrix<Weight> &Layer::getWeights() const {
            return weights;
        }

        void Layer::setWeights(const Perception_Element_Matrix<Weight> &weights) {
            Layer::weights = weights;
        }



    } // Perception
} // Layers