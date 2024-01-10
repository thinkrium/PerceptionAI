cmake_minimum_required(VERSION 3.0)
project(PerceptionAI)

set(CMAKE_CXX_STANDARD 17)

add_library(PerceptionAI SHARED Perception.cpp
        Perception_Elements/Perception_Element.cpp
        Perception_Elements/Perception_Element.h
        Nodes/Node.cpp
        Nodes/Node.h
        Biases/Bias.cpp
        Biases/Bias.h
        Weights/Weight.cpp
        Weights/Weight.h)
