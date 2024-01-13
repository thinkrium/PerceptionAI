//
// Created by thome on 1/13/2024.
//

#include "Perception_Network.h"

namespace Perception {
    namespace Network {

        Perception_Network::Perception_Network() {}

        const Layer &Perception_Network::getInputLayer() const {
            return inputLayer;
        }

        void Perception_Network::setInputLayer(const Layer &inputLayer) {
            Perception_Network::inputLayer = inputLayer;
        }

        const vector<Layer> &Perception_Network::getInnerLayers() const {
            return innerLayers;
        }

        void Perception_Network::setInnerLayers(const vector<Layer> &innerLayers) {
            Perception_Network::innerLayers = innerLayers;
        }

        const Layer &Perception_Network::getOutputLayer() const {
            return outputLayer;
        }

        void Perception_Network::setOutputLayer(const Layer &outputLayer) {
            Perception_Network::outputLayer = outputLayer;
        }

        Perception_Network::~Perception_Network() {

        }
    } // Perception
} // Network