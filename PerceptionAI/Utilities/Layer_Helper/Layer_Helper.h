//
// Created by thome on 1/13/2024.
//

#ifndef PERCEPTIONAI_LAYER_HELPER_H
#define PERCEPTIONAI_LAYER_HELPER_H

#include "../../Network_Elements/Layers/Layer.h"
#include "../Enumerations/Perception_Enumerations.h"
#include "../../Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.h"
#include "../../Network_Elements/Results/Result.h"

#include "cmath"

using namespace std;

using namespace Perception::Layers;
using namespace Perception::Network::Utilities::Enumerations;
using namespace Perception::Network::Elements::Vectors;
using namespace Perception::Network::Elements::Results;

namespace Perception {
    namespace Network {
        namespace Utilities {

            class Layer_Helper {
            private:
                Perception_Maths perceptionMaths;

                template<typename typeName>
                vector<float> getFloatsFromPerceptionElementVector(Perception_Element_Vector<typeName> elementType);

                template<typename typeName>
                vector<float> getFloatsFromPerceptionElementVector(vector<typeName> elementType);

            public:
                Layer_Helper();

                const Perception_Maths &getPerceptionMaths() const;

                void setPerceptionMaths(const Perception_Maths &perceptionMaths);


                virtual ~Layer_Helper();

                void Prepare_Forward_Propagation_Without_Activating(Layer &previousLayer, Layer &currentLayer);
                void Prepare_Backward_Propagation(Layer &layer);
                Perception_Element_Vector<Node> Propagate_Forward(Layer layer);
                Perception_Element_Vector<Node> Propagate_Backward(Layer layer);
                void Activate_Nodes_With(Layer &layer, Perception_Enumerations::activationMethod activationMethod);
                void Activate_Nodes_With_ReLU(Layer &layer);
                void Activate_Node_With_ReLU(Node *node);
                double Sum_The_Layers_Nodes_Exponential_Values(Layer &layer);
                void Activate_Nodes_With_Softmax(Layer &layer);
                void Activate_Node_With_Softmax(Node *node, double layersExponentialSum);
                void Calculate_Loss_With_Categorical_Cross_Entropy(Layer &outputLayer, Result &result);
                void Calculate_Derivative_Of_ReLu(Node *node);
                void Calculate_Derivative_Of_Softmax(Node *node, int targetNodeIndex, Layer currentLayer);
                void Calculate_Categorical_Cross_Entropy_Derivative_of_Node(Node *node, Result *result);
                void Calculate_Cross_Entropy_With_Softmax_Derivative_Of_Node(Node *node, int nodeIndex, Result *result);

            };

        } // Perception
    } // Network
} // Utilities

#endif //PERCEPTIONAI_LAYER_HELPER_H
