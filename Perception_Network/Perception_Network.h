//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_NETWORK_H
#define PERCEPTIONAI_PERCEPTION_NETWORK_H

#include "../Network_Elements/Layers/Layer.h"
#include "../Utilities/Layer_Helper/Layer_Helper.h"

using namespace Perception::Layers;

namespace Perception {
    namespace Network {

        class Perception_Network {
        public:
            Perception_Network();

            Perception_Network(int layerCount, int nodesPerLayer);

            virtual ~Perception_Network();

            const Layer &getInputLayer() const;

            void setInputLayer(const Layer &inputLayer);

            const vector<Layer> &getInnerLayers() const;

            void setInnerLayers(const vector<Layer> &innerLayers);

            void setInnerLayers( );

            void setInputLayer( );

            void setOutputLayer( );

            const Layer &getOutputLayer() const;

            void setOutputLayer(const Layer &outputLayer);


            void instantiateNetwork(int innerLayerCount, int nodeCountPerLayer);

            void startNetwork();

            int getInnerLayerCount() const;

            void setInnerLayerCount(int innerLayerCount);

            int getNodeCountPerInnerLayer() const;

            void setNodeCountPerInnerLayer(int nodeCountPerLayer);

            int getInputLayerNodeCount() const;

            void setInputLayerNodeCount(int inputLayerNodeCount);

            int getOutputLayerNodeCount() const;

            void setOutputLayerNodeCount(int outputLayerNodeCount);

            void
            instantiateLayersWeights(Layer &layer);

            void instantiateLayersLocalNodes(Layer &layer);

            void instantiateLayersBiases(Layer &layer);
        private:
            Layer inputLayer;
            vector <Layer> innerLayers;
            Layer outputLayer;

            int inputLayerNodeCount;

            int innerLayerCount;
            int nodeCountPerInnerLayer;

            int outputLayerNodeCount;
        };

    } // Perception
} // Network

#endif //PERCEPTIONAI_PERCEPTION_NETWORK_H
