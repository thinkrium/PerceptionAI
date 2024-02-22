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

                        if(!this->isHealthStatusIsSet() ) { throw runtime_error("nope"); }
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

                const vector<string> &Status::getErrorMessages() const {
                    return errorMessages;
                }

                void Status::setErrorMessages(const vector<string> &errorMessages) {
                    Status::errorMessages = errorMessages;
                }

                bool Status::operator==(const Status &rhs) const {
                    return healthStatus == rhs.healthStatus &&
                           errorMessages == rhs.errorMessages &&
                           healthStatusIsSet == rhs.healthStatusIsSet;
                }

                bool Status::operator!=(const Status &rhs) const {
                    return !(rhs == *this);
                }

                void Status::addErrorMessage(string errorMessage) {
                      this->errorMessages.push_back(errorMessage);
                }


            } // Perception
        } // Network
    } // Elements
} // Statuses