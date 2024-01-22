cmake_minimum_required(VERSION 3.0)
project(PerceptionAI)

set(CMAKE_CXX_STANDARD 17)

add_library(PerceptionAI SHARED Perception.cpp
        Network_Elements/Perception_Elements/Individual/Perception_Element.cpp
        Network_Elements/Perception_Elements/Individual/Perception_Element.h
        Network_Elements/Nodes/Node.cpp
        Network_Elements/Nodes/Node.h
        Network_Elements/Biases/Bias.cpp
        Network_Elements/Biases/Bias.h
        Network_Elements/Weights/Weight.cpp
        Network_Elements/Weights/Weight.h
        Network_Elements/Layers/Layer.cpp
        Network_Elements/Layers/Layer.h
        Perception_Network/Perception_Network.cpp
        Perception_Network/Perception_Network.h
        Utilities/Layer_Helper/Layer_Helper.cpp
        Utilities/Layer_Helper/Layer_Helper.h
        Utilities/Maths/Perception_Maths.cpp
        Utilities/Maths/Perception_Maths.h
        Utilities/Enumerations/Perception_Enumerations.h
        Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.cpp
        Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.h
        Network_Elements/Statuses/Status.cpp
        Network_Elements/Statuses/Status.h
        Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.cpp
        Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.h)

add_executable(Perception_AI  Perception.cpp
        Network_Elements/Perception_Elements/Individual/Perception_Element.cpp
        Network_Elements/Perception_Elements/Individual/Perception_Element.h
        Network_Elements/Nodes/Node.cpp
        Network_Elements/Nodes/Node.h
        Network_Elements/Biases/Bias.cpp
        Network_Elements/Biases/Bias.h
        Network_Elements/Weights/Weight.cpp
        Network_Elements/Weights/Weight.h
        main.cpp
        Network_Elements/Layers/Layer.cpp
        Network_Elements/Layers/Layer.h
        Perception_Network/Perception_Network.cpp
        Perception_Network/Perception_Network.h
        Utilities/Layer_Helper/Layer_Helper.cpp
        Utilities/Layer_Helper/Layer_Helper.h
        Utilities/Maths/Perception_Maths.cpp
        Utilities/Maths/Perception_Maths.h
        Utilities/Enumerations/Perception_Enumerations.h
        Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.cpp
        Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.h
        Network_Elements/Statuses/Status.cpp
        Network_Elements/Statuses/Status.h
        Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.cpp
        Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.h)
