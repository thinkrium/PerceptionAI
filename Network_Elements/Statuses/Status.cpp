//
// Created by thome on 1/20/2024.
//

#include "Status.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Statuses {
                Status::Status() {}

                Status::~Status() {

                }

                Perception_Enumerations::healthStatus Status::getHealthStatus() const {
                    return healthStatus;
                }

                void Status::setHealthStatus(Perception_Enumerations::healthStatus healthStatus) {
                    Status::healthStatus = healthStatus;
                }

            } // Perception
        } // Network
    } // Elements
} // Statuses