//
// Created by thome on 1/20/2024.
//

#ifndef PERCEPTIONAI_STATUS_H
#define PERCEPTIONAI_STATUS_H

#include "../../Utilities/Enumerations/Perception_Enumerations.h"

using namespace Perception::Network::Utilities::Enumerations;


namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Statuses {

                class Status {
                    Perception_Enumerations::healthStatus healthStatus;
                public:

                    int  setHealthStatusToError( );

                    virtual ~Status();

                    bool healthStatusIsSet;

                    bool isHealthStatusIsSet() const;

                    void setHealthStatusIsSet(bool healthStatusIsSet);

                    Status();

                    Perception_Enumerations::healthStatus getHealthStatus() const;

                    void setHealthStatus(Perception_Enumerations::healthStatus healthStatus);

                };


            } // Perception
        } // Network
    } // Elements
} // Statuses

#endif //PERCEPTIONAI_STATUS_H
