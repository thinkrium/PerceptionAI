cmake_minimum_required(VERSION 3.0)
project(PerceptionAI)

set(CMAKE_CXX_STANDARD 17)

add_library(PerceptionAI SHARED Perception.cpp
        Network/Perception_Elements/Perception_Element.cpp
        Network/Perception_Elements/Perception_Element.h
        Network/Nodes/Node.cpp
        Network/Nodes/Node.h
        Network/Biases/Bias.cpp
        Network/Biases/Bias.h
        Network/Weights/Weight.cpp
        Network/Weights/Weight.h
        Network/Layers/Layer.cpp
        Network/Layers/Layer.h)

add_executable(Perception_AI  Perception.cpp
        Network/Perception_Elements/Perception_Element.cpp
        Network/Perception_Elements/Perception_Element.h
        Network/Nodes/Node.cpp
        Network/Nodes/Node.h
        Network/Biases/Bias.cpp
        Network/Biases/Bias.h
        Network/Weights/Weight.cpp
        Network/Weights/Weight.h
        main.cpp
        Network/Layers/Layer.cpp
        Network/Layers/Layer.h)
