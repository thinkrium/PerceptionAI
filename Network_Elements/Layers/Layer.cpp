//
// Created by thome on 1/11/2024.
//

#include "Layer.h"


namespace Perception {
    namespace Layers {
        Layer::Layer() {

            this->setNodeCountPerLayer(0);
        }

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

        Layer::Layer(int nodesPerLayer) : nodeCountPerLayer(nodesPerLayer) {
            this->setNodeCountPerLayer(nodesPerLayer);

        }

        int Layer::getNodeCountPerLayer() const {
            return nodeCountPerLayer;
        }

        void Layer::setNodeCountPerLayer(int nodesPerLayer) {
            Layer::nodeCountPerLayer = nodesPerLayer;
        }

        /*
         * Checks if the node count per layer variable is equal to zero
         * and if it is it returns first
         *
         * if not then it instantiates empty nodes by the count of nodes per layer
         */
        void Layer::initiateAllLocalNodesWithRandomValues() {
            if (this->getNodeCountPerLayer() == 0) return;

            this->setLocalNodes(
                    vector<Node>(
                            this->getNodeCountPerLayer(),
                            Node(
                                    0
                            )
                    )
            );

            this->populatePerceptionElementVectorWithRandomValues(
                    (vector<Perception_Element> &)
                            this->getLocalNodes());

         }

        void Layer::initiateAllBiasesWithRandomValues() {

            int numberOfBiases = this->getBiases().size();
            if (
                    numberOfBiases == 0
                    ||
                    numberOfBiases != this->getNodeCountPerLayer()
                ) {
                return;
            }

            this->setBiases(
                    vector<Bias>(
                            numberOfBiases,
                            Bias(
                                    0
                            )
                    )
            );

            this->populatePerceptionElementVectorWithRandomValues(
                    (vector<Perception_Element> &)
                            this->getBiases());
        }

        void Layer::initiateAllWeightsWithRandomValues() {
            int numberOfInputs = this->getInputNodes().size();
            if (
                    numberOfInputs == 0
                    ||
                    this->getNodeCountPerLayer() == 0
                    ) {
                return;
            }

            vector< vector<Weight>> weights (
                    numberOfInputs,
                    vector<Weight>(
                            getNodeCountPerLayer(),
                            Weight()));

            this->setWeights(weights);

            this->populatePerceptionElement2dVectorWithRandomValues(
                    (vector<vector<Perception_Element>> &)
                            this->getWeights());
        }

        void Layer::populatePerceptionElementVectorWithRandomValues(vector<Perception_Element> &element_vector) {
           int vectorSize = element_vector.size();

           for (int vectorIndex = 0; vectorIndex < vectorSize; vectorIndex++) {
               element_vector[vectorIndex].setValue(Perception_Maths().generateRandomValue());
           }
        }

        void Layer::populatePerceptionElement2dVectorWithRandomValues(vector<vector <Perception_Element>> &element_vector) {
            int vectorRowSize = element_vector.size();
            int vectorColumnSize = element_vector[0].size();

            for (int vectorRowIndex = 0; vectorRowIndex < vectorRowSize; vectorRowIndex++) {
                for (int vectorColumnIndex = 0; vectorColumnIndex < vectorColumnSize; vectorColumnIndex++) {
                    element_vector[vectorRowIndex][vectorColumnIndex]
                        .setValue(Perception_Maths().generateRandomValue());
                }
            }

        }
    } // Perception
} // Layers