//
// Created by thome on 1/11/2024.
//

#include "Layer.h"


namespace Perception {
    namespace Layers {
        Layer::Layer() {

            this->setNodeCountPerLayer(0);
            this->setCurrentLayersNodeCountIsSet(true);
            this->setPreviousLayersNodeCountIsSet(false);

            this->setInputNodesAreSet(false);
            this->setLocalNodesAreSet(false);
            this->setOutputNodesAreSet(false);
            this->setBiasesAreSet(false);
            this->setWeightsAreSet(false);

            //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

             //this->setHealthStatus(Perception_Enumerations::healthStatus::error)
        }

        Layer::~Layer() = default;



        /***
         * sending in this parameter does not set the actual nodes per layer
         * only the parameter nodeCountPerLayer for use later
         * @param nodesPerLayer
         */
        Layer::Layer(int nodesPerLayer) : nodeCountPerLayer(nodesPerLayer) {
            this->setNodeCountPerLayer(nodesPerLayer);
            this->setCurrentLayersNodeCountIsSet(true);
            this->setPreviousLayersNodeCountIsSet(false);

            this->setInputNodesAreSet(false);
            this->setLocalNodesAreSet(false);
            this->setOutputNodesAreSet(false);
            this->setBiasesAreSet(false);
            this->setWeightsAreSet(false);

            //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

        }

        int Layer::getNodeCountPerLayer() {
            try {

                if(!this->isCurrentLayersNodeCountIsSet()) { throw "nope"; }
                return this->nodeCountPerLayer;
            }
            catch (exception e) {
                  //this->setHealthStatus(Perception_Enumerations::healthStatus::error)
//
            }

            return -1;
        }

        void Layer::setNodeCountPerLayer(int nodesPerLayer) {

            this->nodeCountPerLayer = nodesPerLayer;
            this->setCurrentLayersNodeCountIsSet(true);
        }


        int Layer::getNodeCountPerPreviousLayerGoingPropagatingForwards() {

            try {

                if(!this->isPreviousLayersNodeCountIsSet()) { throw "nope"; }
                return this->nodeCountPerPreviousLayerGoingPropagatingForwards;
            }
            catch (exception e) {
                  //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

            }

            return -1;
        }

        void Layer::setNodeCountPerPreviousLayerGoingPropagatingForwards(
                int nodeCountPerPreviousLayerGoingPropagatingForwards) {
            this->nodeCountPerPreviousLayerGoingPropagatingForwards = nodeCountPerPreviousLayerGoingPropagatingForwards;

             this->setPreviousLayersNodeCountIsSet(true);


        }

        const Perception_Element_Vector<Node> & Layer::getInputNodes() {

            try {

                if(!this->isInputNodesAreSet()) { throw "nope"; }
                return this->inputNodes;
            }
            catch (exception e) {
                   //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

            }
            return this->inputNodes;
        }


        void Layer::setInputNodes(const Perception_Element_Vector<Node> &inputNodes) {
            Layer::inputNodes = inputNodes;
            this->setInputNodesAreSet(true);
        }

        const Perception_Element_Vector<Node> & Layer::getLocalNodes() {
            try {

                if(!this->isLocalNodesAreSet()) { throw "nope"; }
                return localNodes;
            }
            catch (exception e) {
                   //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

            }

            return localNodes;
        }

        void Layer::setLocalNodes(const Perception_Element_Vector<Node> &localNodes) {
            Layer::localNodes = localNodes;
            this->setLocalNodesAreSet(true);
        }

        const Perception_Element_Vector<Node> & Layer::getOutputNodes() {
            try {

                if(!this->isOutputNodesAreSet()) { throw "nope"; }
                return outputNodes;
            }
            catch (exception e) {
                  //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

            }
            return outputNodes;
        }

        void Layer::setOutputNodes(const Perception_Element_Vector<Node> &outputNodes) {
            Layer::outputNodes = outputNodes;
            this->setOutputNodesAreSet(true);
        }

        const Perception_Element_Vector<Bias> & Layer::getBiases() {
            try {

                if(!this->isBiasesAreSet()) { throw "nope"; }
                return biases;
            }
            catch (exception e) {
                  //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

            }
            return biases;
        }

        void Layer::setBiases(const Perception_Element_Vector<Bias> &biases) {
            Layer::biases = biases;
            this->setBiasesAreSet(true);
        }

        const Perception_Element_Matrix<Weight> & Layer::getWeights() {
            try {

                if(!this->isWeightsAreSet()) { throw "nope"; }
                return weights;
            }
            catch (exception e) {
                  //this->setHealthStatus(Perception_Enumerations::healthStatus::error)

            }
            return weights;
        }

        void Layer::setWeights(const Perception_Element_Matrix<Weight> &weights) {
            Layer::weights = weights;
            this->setWeightsAreSet(false);
        }

        bool Layer::isInputNodesAreSet() const {
            return inputNodesAreSet;
        }

        void Layer::setInputNodesAreSet(bool inputNodesAreSet) {
            Layer::inputNodesAreSet = inputNodesAreSet;
        }

        bool Layer::isLocalNodesAreSet() const {
            return localNodesAreSet;
        }

        void Layer::setLocalNodesAreSet(bool localNodesAreSet) {
            Layer::localNodesAreSet = localNodesAreSet;
        }

        bool Layer::isOutputNodesAreSet() const {
            return outputNodesAreSet;
        }

        void Layer::setOutputNodesAreSet(bool outputNodesAreSet) {
            Layer::outputNodesAreSet = outputNodesAreSet;
        }

        bool Layer::isBiasesAreSet() const {
            return biasesAreSet;
        }

        void Layer::setBiasesAreSet(bool biasesAreSet) {
            Layer::biasesAreSet = biasesAreSet;
        }

        bool Layer::isWeightsAreSet() const {
            return weightsAreSet;
        }

        void Layer::setWeightsAreSet(bool weightsAreSet) {
            Layer::weightsAreSet = weightsAreSet;
        }

        bool Layer::isCurrentLayersNodeCountIsSet() const {
            return currentLayersNodeCountIsSet;
        }

        void Layer::setCurrentLayersNodeCountIsSet(bool currentLayersNodeCountIsSet) {
            Layer::currentLayersNodeCountIsSet = currentLayersNodeCountIsSet;
        }

        bool Layer::isPreviousLayersNodeCountIsSet() const {
            return previousLayersNodeCountIsSet;
        }

        void Layer::setPreviousLayersNodeCountIsSet(bool previousLayersNodeCountIsSet) {
            Layer::previousLayersNodeCountIsSet = previousLayersNodeCountIsSet;
        }


    } // Perception
} // Layers