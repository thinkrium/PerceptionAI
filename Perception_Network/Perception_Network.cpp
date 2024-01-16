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
            return this->inputLayer;
        }

        void Perception_Network::setInputLayer(const Layer &inputLayer) {
            this->inputLayer = inputLayer;
        }

        const vector<Layer> &Perception_Network::getInnerLayers() const {
            return this->innerLayers;
        }

        void Perception_Network::setInnerLayers(const vector<Layer> &innerLayers) {
            this->innerLayers = innerLayers;
        }

        const Layer &Perception_Network::getOutputLayer() const {
            return this->outputLayer;
        }

        void Perception_Network::setOutputLayer(const Layer &outputLayer) {
            this->outputLayer = outputLayer;
        }

        int Perception_Network::getInnerLayerCount() const {
            return this->innerLayerCount;
        }

        void Perception_Network::setInnerLayerCount(int innerLayerCount) {
            this->innerLayerCount = innerLayerCount;
        }

        int Perception_Network::getNodeCountPerInnerLayer() const {
            return this->nodeCountPerInnerLayer;
        }

        void Perception_Network::setNodeCountPerInnerLayer(int nodeCountPerLayer) {
            this->nodeCountPerInnerLayer = nodeCountPerLayer;
        }

        void Perception_Network::startNetwork() {

        }

        Perception_Network::~Perception_Network() {

        }

        void Perception_Network::instantiateNetwork(int innerLayerCount, int nodeCountPerLayer) {

            this->setInputLayerNodeCount(3);

            this->setInnerLayerCount(innerLayerCount);
            this->setNodeCountPerInnerLayer(nodeCountPerLayer);

            this->setOutputLayerNodeCount(3);

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


            vector< Layer>  innerLayers(this->getInnerLayerCount());

            for (int index = 0; index < this->getInnerLayerCount(); index++) {

                innerLayers[index] = Layer(this->getNodeCountPerInnerLayer());

                if(index == 0) {
                    // this is the input layer
                    innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards( 3 );
                }
                else {
                    innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards(
                            innerLayers[index - 1].getNodeCountPerLayer()
                    );
                }



                // set local nodes
                vector<Node> localNodes(this->getOutputLayerNodeCount(), Node());

                innerLayers[index].setLocalNodes(localNodes);

                // set weights
                vector<vector<Weight> > weights(
                        // this is the input layer count
                        innerLayers[index].getNodeCountPerPreviousLayerGoingPropagatingForwards(),
                        vector<Weight>(this->getNodeCountPerInnerLayer(), Weight()));

                innerLayers[index].setWeights(weights);

                // set biases
                vector<Bias> biases(innerLayers[index].getNodeCountPerLayer(), Bias());

                innerLayers[index].setBiases(biases);

            }

            this->setInnerLayers(innerLayers);

        }

        void Perception_Network::setInputLayer() {

            if(this->getInputLayerNodeCount() == 0) return;

            Layer inputLayer(this->getInputLayerNodeCount());

            vector<Node> inputs(this->getInputLayerNodeCount());

            for(int nodeCountIndex = 0; nodeCountIndex < this->getInputLayerNodeCount(); nodeCountIndex++) {
                inputs[nodeCountIndex].setValue(nodeCountIndex + 1);
            }

            inputLayer.setLocalNodes(inputs);

            this->setInputLayer(inputLayer);
        }

        void Perception_Network::setOutputLayer() {

            Layer lastInnerLayer = this->innerLayers[this->innerLayers.size() - 1] ;

            int inputCount =  lastInnerLayer.getNodeCountPerLayer();

            Layer outputLayer(this->getOutputLayerNodeCount());

            // set local nodes
            vector<Node> localNodes(this->getOutputLayerNodeCount(), Node());

            outputLayer.setLocalNodes(localNodes);

            // set weights
            vector<vector<Weight> > weights(
                    inputCount,
                    vector<Weight>(this->getOutputLayerNodeCount(), Weight()));

            outputLayer.setWeights(weights);

            // set biases
            vector<Bias> biases(this->getOutputLayerNodeCount(), Bias());

            outputLayer.setBiases(biases);

            // get the output node count from the last inner layer going forward
            outputLayer.setNodeCountPerPreviousLayerGoingPropagatingForwards(
                   inputCount
            );


            this->setOutputLayer(outputLayer);
        }

        int Perception_Network::getInputLayerNodeCount() const {
            return this->inputLayerNodeCount;
        }

        void Perception_Network::setInputLayerNodeCount(int inputLayerNodeCount) {
            this->inputLayerNodeCount = inputLayerNodeCount;
        }

        int Perception_Network::getOutputLayerNodeCount() const {
            return this->outputLayerNodeCount;
        }

        void Perception_Network::setOutputLayerNodeCount(int outputLayerNodeCount) {
            this->outputLayerNodeCount = outputLayerNodeCount;
        }
    } // Perception
} // Network