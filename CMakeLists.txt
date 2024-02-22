cmake_minimum_required(VERSION 3.14)
project(PerceptionAI)

set(CMAKE_CXX_STANDARD 17)

add_library(PerceptionAI_Library SHARED Perception.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Individual/Perception_Element.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Individual/Perception_Element.h
        PerceptionAI/Network_Elements/Nodes/Node.cpp
        PerceptionAI/Network_Elements/Nodes/Node.h
        PerceptionAI/Network_Elements/Biases/Bias.cpp
        PerceptionAI/Network_Elements/Biases/Bias.h
        PerceptionAI/Network_Elements/Weights/Weight.cpp
        PerceptionAI/Network_Elements/Weights/Weight.h
        PerceptionAI/Network_Elements/Layers/Layer.cpp
        PerceptionAI/Network_Elements/Layers/Layer.h
        PerceptionAI/Perception_Network/Perception_Network.cpp
        PerceptionAI/Perception_Network/Perception_Network.h
        PerceptionAI/Utilities/Layer_Helper/Layer_Helper.cpp
        PerceptionAI/Utilities/Layer_Helper/Layer_Helper.h
        PerceptionAI/Utilities/Maths/Perception_Maths.cpp
        PerceptionAI/Utilities/Maths/Perception_Maths.h
        PerceptionAI/Utilities/Enumerations/Perception_Enumerations.h
        PerceptionAI/Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.h
        PerceptionAI/Network_Elements/Statuses/Status.cpp
        PerceptionAI/Network_Elements/Statuses/Status.h
        PerceptionAI/Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.h
        PerceptionAI/Network_Elements/Results/Result.cpp
        PerceptionAI/Network_Elements/Results/Result.h
        PerceptionAI/Utilities/GUID/GUID.h)

add_executable(PerceptionAI_EXE  Perception.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Individual/Perception_Element.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Individual/Perception_Element.h
        PerceptionAI/Network_Elements/Nodes/Node.cpp
        PerceptionAI/Network_Elements/Nodes/Node.h
        PerceptionAI/Network_Elements/Biases/Bias.cpp
        PerceptionAI/Network_Elements/Biases/Bias.h
        PerceptionAI/Network_Elements/Weights/Weight.cpp
        PerceptionAI/Network_Elements/Weights/Weight.h
        main.cpp
        PerceptionAI/Network_Elements/Layers/Layer.cpp
        PerceptionAI/Network_Elements/Layers/Layer.h
        PerceptionAI/Perception_Network/Perception_Network.cpp
        PerceptionAI/Perception_Network/Perception_Network.h
        PerceptionAI/Utilities/Layer_Helper/Layer_Helper.cpp
        PerceptionAI/Utilities/Layer_Helper/Layer_Helper.h
        PerceptionAI/Utilities/Maths/Perception_Maths.cpp
        PerceptionAI/Utilities/Maths/Perception_Maths.h
        PerceptionAI/Utilities/Enumerations/Perception_Enumerations.h
        PerceptionAI/Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.h
        PerceptionAI/Network_Elements/Statuses/Status.cpp
        PerceptionAI/Network_Elements/Statuses/Status.h
        PerceptionAI/Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.cpp
        PerceptionAI/Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.h
        PerceptionAI/Network_Elements/Results/Result.cpp
        PerceptionAI/Network_Elements/Results/Result.h
        PerceptionAI/Utilities/GUID/GUID.h)


add_subdirectory(PerceptionAI_Tests)

