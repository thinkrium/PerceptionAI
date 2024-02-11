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

    perceptionNetwork.startNetwork();


    Perception_Maths perceptionMaths;

    vector<vector<float>> left {
             {1,2,3}
            ,{1,2,3}
            ,{1,2,3}
    };

    vector<vector<float>> right {
             {1,2,3}
            ,{1,2,3}
            ,{1,2,3}
    };

    vector<vector<float>> expected_result {
             {6,12,18}
            ,{6,12,18}
            ,{6,12,18}
    };

    // assert

    vector<vector<float>> actual_result = perceptionMaths.dotProduct(left,right);
    // test


    return 0;
}