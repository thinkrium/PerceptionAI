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

using namespace Perception::Network::Elements::Nodes;
using namespace Perception::Network::Elements::Weights;
using namespace Perception::Network::Elements::Biases;

using namespace Perception::Network::Utilities::Maths;

namespace Perception {
    namespace Layers {

        class Layer {

        private:
            Perception_Element_Vector inputNodes;
            Perception_Element_Vector localNodes;
            Perception_Element_Vector outputNodes;
            Perception_Element_Vector biases;

            Perception_Element_Matrix weights;

            int nodeCountPerLayer;
            int nodeCountPerPreviousLayerGoingPropagatingForwards;
        public:

            int getNodeCountPerPreviousLayerGoingPropagatingForwards() const;

            void
            setNodeCountPerPreviousLayerGoingPropagatingForwards(int nodeCountPerPreviousLayerGoingPropagatingForwards);

            explicit Layer(int nodesPerLayer);
            Layer();

            ~Layer();

            const Perception_Element_Vector &getInputNodes() const;

            void setInputNodes(const Perception_Element_Vector &inputNodes);

            const Perception_Element_Vector &getLocalNodes() const;

            void setLocalNodes(const Perception_Element_Vector &localNodes);

            const Perception_Element_Vector &getOutputNodes() const;

            void setOutputNodes(const Perception_Element_Vector &outputNodes);

            const Perception_Element_Vector &getBiases() const;

            void setBiases(const Perception_Element_Vector &biases);

            const Perception_Element_Matrix &getWeights() const;

            void setWeights(const Perception_Element_Matrix &weights);

            int getNodeCountPerLayer() const;

            void setNodeCountPerLayer(int nodesPerLayer);
        };

    } // Perception
} // Layers

#endif //PERCEPTIONAI_LAYER_H
