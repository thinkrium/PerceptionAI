//
// Created by thome on 1/11/2024.
//

#ifndef PERCEPTIONAI_LAYER_H
#define PERCEPTIONAI_LAYER_H

#include "vector"

#include "../Statuses/Status.h"

#include "../Nodes/Node.h"
#include "../Weights/Weight.h"
#include "../Biases/Bias.h"

#include "../../Utilities/Maths/Perception_Maths.h"

using namespace std;

using namespace Perception::Network::Elements::Nodes;
using namespace Perception::Network::Elements::Weights;
using namespace Perception::Network::Elements::Biases;

using namespace Perception::Network::Utilities::Maths;

using namespace Perception::Network::Elements::Statuses;

namespace Perception {
    namespace Layers {

        class Layer : public Status {

        private:
            Perception_Element_Vector<Node> inputNodes;
            Perception_Element_Vector<Node> localNodes;
            Perception_Element_Vector<Node> outputNodes;
            Perception_Element_Vector<Bias> biases;

            Perception_Element_Matrix<Weight> weights;

            int nodeCountPerLayer;
            int nodeCountPerPreviousLayerGoingPropagatingForwards;

            bool inputNodesAreSet;
            bool localNodesAreSet;
            bool outputNodesAreSet;
            bool biasesAreSet;
            bool weightsAreSet;

            bool currentLayersNodeCountIsSet;
        public:
            bool isInputNodesAreSet() const;

            void setInputNodesAreSet(bool inputNodesAreSet);

            bool isLocalNodesAreSet() const;

            void setLocalNodesAreSet(bool localNodesAreSet);

            bool isOutputNodesAreSet() const;

            void setOutputNodesAreSet(bool outputNodesAreSet);

            bool isBiasesAreSet() const;

            void setBiasesAreSet(bool biasesAreSet);

            bool isWeightsAreSet() const;

            void setWeightsAreSet(bool weightsAreSet);

            bool isCurrentLayersNodeCountIsSet() const;

            void setCurrentLayersNodeCountIsSet(bool currentLayersNodeCountIsSet);

            bool isPreviousLayersNodeCountIsSet() const;

            void setPreviousLayersNodeCountIsSet(bool previousLayersNodeCountIsSet);

        private:
            bool previousLayersNodeCountIsSet;


        public:

            int getNodeCountPerPreviousLayerGoingPropagatingForwards();

            void
            setNodeCountPerPreviousLayerGoingPropagatingForwards(int nodeCountPerPreviousLayerGoingPropagatingForwards);

            explicit Layer(int nodesPerLayer, bool autoGenerateLocalNodes = true );

            Layer();

            ~Layer();

            const Perception_Element_Vector<Node> & getInputNodes();

            void setInputNodes(const Perception_Element_Vector<Node> &inputNodes);

            const Perception_Element_Vector<Node> & getLocalNodes();

            void setLocalNodes(const Perception_Element_Vector<Node> &localNodes);

            const Perception_Element_Vector<Node> & getOutputNodes();

            void setOutputNodes(const Perception_Element_Vector<Node> &outputNodes);

            const Perception_Element_Vector<Bias> & getBiases();

            void setBiases(const Perception_Element_Vector<Bias> &biases);

            int getNodeCountPerLayer();

            const Perception_Element_Matrix<Weight> & getWeights();

            void setWeights(const Perception_Element_Matrix<Weight> &weights);

            void setNodeCountPerLayer(int nodesPerLayer);
        };

    } // Perception
} // Layers

#endif //PERCEPTIONAI_LAYER_H
