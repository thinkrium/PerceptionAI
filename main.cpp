//
// Created by thome on 1/11/2024.
//
#include "iostream"
#include "Perception_Network/Perception_Network.h"

using namespace std;
using namespace Perception::Network;

int main() {

    Perception_Network perceptionNetwork ;

    perceptionNetwork.instantiateNetwork(3, 3);
//
//    perceptionNetwork.startNetwork();


    return 0;
}