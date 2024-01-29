//
// Created by thome on 1/20/2024.
//

#include "exception"
#include "Status.h"

using namespace std;

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Statuses {
                Status::Status() {
                    this->setHealthStatusIsSet(false);
                }

                Status::~Status() = default;

                Perception_Enumerations::healthStatus Status::getHealthStatus() const {
                    try {

                        if(!this->isHealthStatusIsSet() ) { throw "nope"; }
                        return this->healthStatus;
                    }
                    catch (exception e) {
                        return Perception_Enumerations::healthStatus::error;
                    }

                }

                void Status::setHealthStatus(Perception_Enumerations::healthStatus healthStatus) {
                     this->healthStatus = healthStatus;
                     setHealthStatusIsSet(true);
                }

                bool Status::isHealthStatusIsSet() const {
                    return this->healthStatusIsSet;
                }

                void Status::setHealthStatusIsSet(bool healthStatusIsSet) {
                    Status::healthStatusIsSet = healthStatusIsSet;
                }

            } // Perception
        } // Network
    } // Elements
} // Statuses