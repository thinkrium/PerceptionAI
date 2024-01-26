//
// Created by thome on 1/13/2024.
//

#include "Perception_Network.h"

namespace Perception {
    namespace Network {

        Perception_Network::Perception_Network() {

            this->setLayerHelper(Layer_Helper());
        }

        Perception_Network::Perception_Network(int layerCount, int nodesPerLayer) : innerLayerCount(layerCount),
                                                                                    nodeCountPerInnerLayer(nodesPerLayer) {
//            this->setInnerLayerCount(layerCount);
//            this->setNodeCountPerInnerLayer(nodesPerLayer);
//
//            this->setLayerHelper(Layer_Helper());
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

//            this->setInputLayerNodeCount(3);
//
//            this->setInnerLayerCount(innerLayerCount);
//            this->setNodeCountPerInnerLayer(nodeCountPerLayer);
//
//            this->setOutputLayerNodeCount(3);

//            this->setInputLayer();
//            this->setInnerLayers();
//            this->setOutputLayer();


        }

        void Perception_Network::setInnerLayers() {

//            if(
//                this->getInnerLayerCount() == 0
//                ||
//                        this->getNodeCountPerInnerLayer() == 0
//                ) {
//                return;
//            }
//
//
//            vector< Layer>  innerLayers(this->getInnerLayerCount());
//
//            for (int index = 0; index < this->getInnerLayerCount(); index++) {
//
//                innerLayers[index] = Layer(this->getNodeCountPerInnerLayer());
//
//                if(index == 0) {
//                    // this is the input layer
//                    innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards( 3 );
//                }
//                else {
//                    innerLayers[index].setNodeCountPerPreviousLayerGoingPropagatingForwards(
//                            innerLayers[index - 1].getNodeCountPerLayer()
//                    );
//                }
//
//
//
//                this->instantiateLayersLocalNodes(innerLayers[index]);
//                this->instantiateLayersWeights(innerLayers[index]);
//                this->instantiateLayersBiases(innerLayers[index]);
//
//
//            }
//
//            this->setInnerLayers(innerLayers);

        }

        void Perception_Network::setInputLayer() {

//            if(this->getInputLayerNodeCount() == 0) return;
//
//            Layer inputLayer(this->getInputLayerNodeCount());
//
//            Perception_Element_Vector<Node> inputs(this->getInputLayerNodeCount());
//
//            for(int nodeCountIndex = 0; nodeCountIndex < this->getInputLayerNodeCount(); nodeCountIndex++) {
//
//                Node node(nodeCountIndex + 1);
//
//                inputs.setIndividualElement(nodeCountIndex,  node);
//            }
//
//            inputLayer.setOutputNodes(inputs); // in the input layer there is no preparation to perform
//                                               // the outputs are the inputs
//
//            this->setInputLayer(inputLayer);
        }

        void Perception_Network::setOutputLayer() {

//            Layer lastInnerLayer = this->innerLayers[this->innerLayers.size() - 1] ;
//
//            int inputCount =  lastInnerLayer.getNodeCountPerLayer();
//
//            Layer outputLayer(this->getOutputLayerNodeCount());
//
//            // get the output node count from the last inner layer going forward
//            outputLayer.setNodeCountPerPreviousLayerGoingPropagatingForwards(
//                    inputCount
//            );
//
//
//            this->instantiateLayersLocalNodes(outputLayer);
//            this->instantiateLayersWeights(outputLayer);
//            this->instantiateLayersBiases(outputLayer);
//
//
//            this->setOutputLayer(outputLayer);
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

        void Perception_Network::instantiateLayersWeights(Layer &layer) {
            // set weights

//            vector<vector<Weight> > weights(
//                    // this is the input layer count
//                    layer.getNodeCountPerPreviousLayerGoingPropagatingForwards(),
//                    vector<Weight>(this->getNodeCountPerInnerLayer() ));
//
//            for(int previousLayerNodeCountWeightIndex = 0; previousLayerNodeCountWeightIndex < this->getNodeCountPerInnerLayer(); previousLayerNodeCountWeightIndex++) {
//                for (int currentLayerNodeCountWeightIndex = 0; currentLayerNodeCountWeightIndex <
//                                                               this->getNodeCountPerInnerLayer(); currentLayerNodeCountWeightIndex++) {
//                    weights[previousLayerNodeCountWeightIndex][currentLayerNodeCountWeightIndex] = Weight();
//                }
//            }

         //   layer.setWeights(weights);

        }

        void Perception_Network::instantiateLayersLocalNodes(Layer &layer) {
//            // set local nodes
//            Perception_Element_Vector<Node> localNodes(this->getNodeCountPerInnerLayer() );
//
//             layer.setLocalNodes(localNodes);

        }

        void Perception_Network::instantiateLayersBiases(Layer &layer) {
            // set local nodes
            Perception_Element_Vector<Bias> biases(this->getNodeCountPerInnerLayer() );

            layer.setBiases(biases);


        }

        const Layer_Helper &Perception_Network::getLayerHelper() const {
            return layerHelper;
        }

        void Perception_Network::setLayerHelper(const Layer_Helper &layerHelper) {
            Perception_Network::layerHelper = layerHelper;
        }
    } // Perception
} // Network