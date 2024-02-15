//
// Created by thome on 1/11/2024.
//
#include "iostream"
#include "PerceptionAI/Perception_Network/Perception_Network.h"

using namespace std;
using namespace Perception::Network;

int main() {

    Perception_Network perceptionNetwork ;

    perceptionNetwork.instantiateNetwork(3, 3);

    // need to fix this
    // output nodes are kicking back an error even
    // though they should be set
    // it looks like the local nodes are set
    // so for input layer which is appropriate and what conditional do i need
//    perceptionNetwork.startNetwork();

    return 0;
}