include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

Set(Lib_Sources
)
add_executable(PerceptionAI_Tests


        ../../../PerceptionAI/Perception.cpp
        ../../../PerceptionAI/PerceptionAI/Network_Elements/Perception_Elements/Individual/Perception_Element.cpp
        ../../PerceptionAI/Network_Elements/Perception_Elements/Individual/Perception_Element.h
        ../../PerceptionAI/Network_Elements/Nodes/Node.cpp
        ../../PerceptionAI/Network_Elements/Nodes/Node.h
        ../../PerceptionAI/Network_Elements/Biases/Bias.cpp
        ../../PerceptionAI/Network_Elements/Biases/Bias.h
        ../../PerceptionAI/Network_Elements/Weights/Weight.cpp
        ../../PerceptionAI/Network_Elements/Weights/Weight.h
        ../../PerceptionAI/Network_Elements/Layers/Layer.cpp
        ../../PerceptionAI/Network_Elements/Layers/Layer.h
        ../../PerceptionAI/Perception_Network/Perception_Network.cpp
        ../../PerceptionAI/Perception_Network/Perception_Network.h
        ../../PerceptionAI/Utilities/Layer_Helper/Layer_Helper.cpp
        ../../PerceptionAI/Utilities/Layer_Helper/Layer_Helper.h
        ../../PerceptionAI/Utilities/Maths/Perception_Maths.cpp
        ../../PerceptionAI/Utilities/Maths/Perception_Maths.h
        ../../PerceptionAI/Utilities/Enumerations/Perception_Enumerations.h
        ../../PerceptionAI/Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.cpp
        ../../PerceptionAI/Network_Elements/Perception_Elements/Matrices/Perception_Element_Matrix.h
        ../../PerceptionAI/Network_Elements/Statuses/Status.cpp
        ../../PerceptionAI/Network_Elements/Statuses/Status.h
        ../../PerceptionAI/Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.cpp
        ../../PerceptionAI/Network_Elements/Perception_Elements/Vectors/Perception_Element_Vector.h


        #############################
        Perception_Maths_Test.cpp
        Layer_Helper_Test.cpp
        ../../PerceptionAI/Network_Elements/Results/Result.cpp
        ../../PerceptionAI/Network_Elements/Results/Result.h
        ../../PerceptionAI/Utilities/GUID/GUID.h
        Results_Test.cpp)

#target_link_libraries(PerceptionAI_Tests PerceptionAI_EXE)
target_link_libraries(PerceptionAI_Tests gtest gtest_main)
