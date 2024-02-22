//
// Created by thome on 2/21/2024.
//


#include "../../Utilities/GUID/GUID.h"
#include "../Perception_Elements/Vectors/Perception_Element_Vector.h"
#include "../Statuses/Status.h"

using namespace Perception::Network::Utilities::GUID;
using namespace Perception::Network::Elements::Vectors;
using namespace Perception::Network::Elements::Statuses;

#ifndef PERCEPTIONAI_RESULTS_H
#define PERCEPTIONAI_RESULTS_H

namespace Perception {
    namespace Network {
        namespace Elements {
           namespace Results {
               class Result : public Status {

                   /**
                    * This is the array holding the One Hot Encoded Targets
                    * @type {number[]}
                    */
                   Perception_Element_Vector <Perception_Element> One_Hot_Encoded_Targets;

                   /**
                    * The size of the one hot encoded targets array
                    * @type {number }
                    */
                   int One_Hot_Encoded_Targets_Count;

                   /**
                    * all the lasses on the output added up
                    * @type {number }
                    */
                   float Total_Loss;

                   /**
                    * losses per node as array
                    * @type {number[]}
                    */
                   Perception_Element_Vector <Perception_Element> Losses;

                   /**
                    * list of loss derivatives
                    * @type {number[]}
                    */

               public:
                   ~Result() override;

                   const Perception_Element_Vector <Perception_Element> &getOneHotEncodedTargets() const;

                   void
                   setOneHotEncodedTargets(const Perception_Element_Vector <Perception_Element> &oneHotEncodedTargets);

                   int getIndexOfOneHotEncodedTargetSetToTrue();

                   int getOneHotEncodedTargetsCount() const;

                   void setOneHotEncodedTargetsCount(int oneHotEncodedTargetsCount);

                   float getTotalLoss() const;

                   void setTotalLoss(float totalLoss);

                   const Perception_Element_Vector <Perception_Element> &getLosses() const;

                   void setLosses(const Perception_Element_Vector <Perception_Element> &losses);

                   float getConfidenceInPrediction() const;

                   void setConfidenceInPrediction(float confidenceInPrediction);

                   bool operator==(const Result &rhs) const;

                   bool operator!=(const Result &rhs) const;

               private:
                   /**
                    * confidence in prediction which comes from the output of the  activation from the output layer
                    * as it relates to the expected result
                    */
                   float Confidence_In_Prediction;
               };
           }
        } // Perception
    } // Network
} // Elements

#endif //PERCEPTIONAI_RESULTS_H
