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
            vector<Node> outputNodes;
            vector<Weight> weights;
            vector<Bias> biases;
        };

    } // Perception
} // Layers

#endif //PERCEPTIONAI_LAYER_H
