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

                   bool oneHotEncodedTargetsAreSet;

                   /**
                    * The size of the one hot encoded targets array
                    * @type {number }
                    */
                   int One_Hot_Encoded_Targets_Count;

                   bool oneHotEncodedTargetsCountIsSet;

                   /**
                    * all the lasses on the output added up
                    * @type {number }
                    */
                   float Total_Loss;
               public:
                   Result();

                   bool isOneHotEncodedTargetsAreSet() const;

                   void setOneHotEncodedTargetsAreSet(bool oneHotEncodedTargetsAreSet);

                   bool isOneHotEncodedTargetsCountIsSet() const;

                   void setOneHotEncodedTargetsCountIsSet(bool oneHotEncodedTargetsCountIsSet);

                   bool isTotalLossesAreSet() const;

                   void setTotalLossesAreSet(bool totalLossesAreSet);

                   bool isLossesAreSet() const;

                   void setLossesAreSet(bool lossesAreSet);

                   bool isLosseDerivativesAreSet() const;

                   void setLosseDerivativesAreSet(bool losseDerivativesAreSet);

               private:
                   bool totalLossesAreSet;

                   /**
                    * losses per node as array
                    * @type {number[]}
                    */
                   Perception_Element_Vector <Perception_Element> Losses;

                   bool lossesAreSet;

                   /**
                    * list of loss derivatives
                    * @type {number[]}
                    */
                   Perception_Element_Vector <Perception_Element> Loss_Derivatives;

                   bool losseDerivativesAreSet;

               public:
                   ~Result() override;

                   Perception_Element_Vector<Perception_Element> & getOneHotEncodedTargets();

                   void
                   setOneHotEncodedTargets(const Perception_Element_Vector <Perception_Element> &oneHotEncodedTargets);

                   void addLossDerivativeToLossDerivatives(Perception_Element lossDerivative) ;

                   Perception_Element_Vector<Perception_Element> & getLossDerivatives();

                   void setLossDerivatives(const Perception_Element_Vector <Perception_Element> &lossDerivatives);

                   int getIndexOfOneHotEncodedTargetSetToTrue();

                   int getOneHotEncodedTargetsCount();

                   void setOneHotEncodedTargetsCount(int oneHotEncodedTargetsCount);

                   float getTotalLoss();

                   void setTotalLoss(float totalLoss);

                   const Perception_Element_Vector <Perception_Element> &getLosses();

                   void setLosses(const Perception_Element_Vector <Perception_Element> &losses);

                   float getConfidenceInPrediction();

                   void setConfidenceInPrediction(float confidenceInPrediction);


                   bool operator==(const Result &rhs) const;

                   bool operator!=(const Result &rhs) const;

               private:
                   /**
                    * confidence in prediction which comes from the output of the  activation from the output layer
                    * as it relates to the expected result
                    */
                   float Confidence_In_Prediction;
               public:
                   bool isConfidenceInPredictionIsSet() const;

                   void setConfidenceInPredictionIsSet(bool confidenceInPredictionIsSet);

               private:

                   bool confidenceInPredictionIsSet;
               };
           }
        } // Perception
    } // Network
} // Elements

#endif //PERCEPTIONAI_RESULTS_H
