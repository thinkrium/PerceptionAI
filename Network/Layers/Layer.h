//
// Created by thome on 1/11/2024.
//

#ifndef PERCEPTIONAI_LAYER_H
#define PERCEPTIONAI_LAYER_H

#include "vector"

#include "../Nodes/Node.h"
#include "../Weights/Weight.h"
#include "../Biases/Bias.h"

using namespace std;

using namespace Perception::Elements::Nodes;
using namespace Perception::Elements::Weights;
using namespace Perception::Elements::Biases;

namespace Perception {
    namespace Layers {

        class Layer {

        private:
            vector<Node> inputNodes;
            vector<Node> localNodes;
            vector<Node> outputNodes;
        public:
            const vector <Node> &getInputNodes() const;

            void setInputNodes(const vector <Node> &inputNodes);

            const vector <Node> &getLocalNodes() const;

            void setLocalNodes(const vector <Node> &localNodes);

            const vector <Node> &getOutputNodes() const;

            void setOutputNodes(const vector <Node> &outputNodes);

            const vector<vector<Weight>> &getWeights() const;

            void setWeights(const vector<vector<Weight>> &weights);

            const vector <Bias> &getBiases() const;

            void setBiases(const vector <Bias> &biases);

            float getMomentum() const;

            void setMomentum(float momentum);

        private:
            vector<vector<Weight>> weights;
            vector<Bias> biases;

            float momentum;
        public:
            Layer();

            virtual ~Layer();
        };

    } // Perception
} // Layers

#endif //PERCEPTIONAI_LAYER_H
