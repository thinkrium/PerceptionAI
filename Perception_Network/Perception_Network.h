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

            const Layer &getOutputLayer() const;

            void setOutputLayer(const Layer &outputLayer);


            void instantiateNetwork();

            void startNetwork();

            int getLayerCount() const;

            void setLayerCount(int layerCount);

            int getNodesPerLayer() const;

            void setNodesPerLayer(int nodesPerLayer);

        private:
            Layer inputLayer;
            vector <Layer> innerLayers;
            Layer outputLayer;

            int layer_count;
            int nodes_per_layer;
        };

    } // Perception
} // Network

#endif //PERCEPTIONAI_PERCEPTION_NETWORK_H
