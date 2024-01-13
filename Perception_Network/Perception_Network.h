//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_PERCEPTION_NETWORK_H
#define PERCEPTIONAI_PERCEPTION_NETWORK_H

#include "../Network_Elements/Layers/Layer.h"
#include "../Network_Elements/U"
using namespace Perception::Layers;

namespace Perception {
    namespace Network {

        class Perception_Network {

            Layer inputLayer;
            vector <Layer> innerLayers;
            Layer outputLayer;

        };

    } // Perception
} // Network

#endif //PERCEPTIONAI_PERCEPTION_NETWORK_H
