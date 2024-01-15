//
// Created by thome on 1/11/2024.
//

#ifndef PERCEPTIONAI_LAYER_H
#define PERCEPTIONAI_LAYER_H

#include "vector"

#include "../Nodes/Node.h"
#include "../Weights/Weight.h"
#include "../Biases/Bias.h"

#include "../../Utilities/Maths/Perception_Maths.h"

using namespace std;

using namespace Perception::Elements::Nodes;
using namespace Perception::Elements::Weights;
using namespace Perception::Elements::Biases;

using namespace Perception::Utilities::Maths;

namespace Perception {
    namespace Layers {

        class Layer {

        private:
            vector<Node> inputNodes;
            vector<Node> localNodes;
            vector<Node> outputNodes;

            int nodeCountPerLayer;
            int nodeCountPerPreviousLayerGoingPropagatingForwards;
        public:
            int getNodeCountPerPreviousLayerGoingPropagatingForwards() const;

            void
            setNodeCountPerPreviousLayerGoingPropagatingForwards(int nodeCountPerPreviousLayerGoingPropagatingForwards);

        public:

            void populatePerceptionElementVectorWithRandomValues(vector<Perception_Element> &element_vector);

            void populatePerceptionElement2dVectorWithRandomValues(vector<vector <Perception_Element>> &element_vector);

            void initiateAllLocalNodesWithRandomValues();

            explicit Layer(int nodesPerLayer);

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

            void initiateAllBiasesWithRandomValues();

            void initiateAllWeightsWithRandomValues();
        private:
            vector<vector<Weight>> weights;
            vector<Bias> biases;

        public:
            Layer();

              ~Layer();

            int getNodeCountPerLayer() const;

            void setNodeCountPerLayer(int nodesPerLayer);
        };

    } // Perception
} // Layers

#endif //PERCEPTIONAI_LAYER_H
