//
// Created by thome on 2/21/2024.
//

#ifndef PERCEPTIONAI_GUID_H
#define PERCEPTIONAI_GUID_H

#include <vector>
#include <iostream>
#include <sstream>
#include <random>
#include <climits>
#include <algorithm>
#include <functional>
#include <string>

namespace Perception {
    namespace Network {
        namespace Utilities {
            namespace GUID {

                class GUID {

                public:
                static unsigned char random_char() {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(0, 255);
                    return static_cast<unsigned char>(dis(gen));
                }

                static std::string generate_GUID(const unsigned int len = 15) {
                    std::stringstream ss;
                    for(auto i = 0; i < len; i++) {
                        auto rc = random_char();
                        std::stringstream hexstream;
                        hexstream << std::hex << int(rc);
                        auto hex = hexstream.str();
                        ss << (hex.length() < 2 ? '0' + hex : hex);
                    }
                    return ss.str();
                }
                };

            } // Perception
        } // Network
    } // Utilities
} // GUID

#endif //PERCEPTIONAI_GUID_H
