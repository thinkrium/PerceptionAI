//
// Created by thome on 2/21/2024.
//

#include "Result.h"

namespace Perception {
    namespace Network {
        namespace Elements {
            namespace Results {
                Result::~Result() {

                }

                bool Result::operator==(const Result &rhs) const {
                    return static_cast<const Status &>(*this) == static_cast<const Status &>(rhs) &&
                           One_Hot_Encoded_Targets == rhs.One_Hot_Encoded_Targets &&
                           One_Hot_Encoded_Targets_Count == rhs.One_Hot_Encoded_Targets_Count &&
                           Total_Loss == rhs.Total_Loss &&
                           Losses == rhs.Losses &&
                           Confidence_In_Prediction == rhs.Confidence_In_Prediction;
                }

                bool Result::operator!=(const Result &rhs) const {
                    return !(rhs == *this);
                }

                const Perception_Element_Vector<Perception_Element> &Result::getOneHotEncodedTargets() const {
                    return One_Hot_Encoded_Targets;
                }

                void Result::setOneHotEncodedTargets(
                        const Perception_Element_Vector<Perception_Element> &oneHotEncodedTargets) {
                    One_Hot_Encoded_Targets = oneHotEncodedTargets;
                }

                int Result::getOneHotEncodedTargetsCount() const {
                    return One_Hot_Encoded_Targets_Count;
                }

                void Result::setOneHotEncodedTargetsCount(int oneHotEncodedTargetsCount) {
                    One_Hot_Encoded_Targets_Count = oneHotEncodedTargetsCount;
                }

                float Result::getTotalLoss() const {
                    return Total_Loss;
                }

                void Result::setTotalLoss(float totalLoss) {
                    Total_Loss = totalLoss;
                }

                const Perception_Element_Vector<Perception_Element> &Result::getLosses() const {
                    return Losses;
                }

                void Result::setLosses(const Perception_Element_Vector<Perception_Element> &losses) {
                    Losses = losses;
                }

                float Result::getConfidenceInPrediction() const {
                    return Confidence_In_Prediction;
                }

                void Result::setConfidenceInPrediction(float confidenceInPrediction) {
                    Confidence_In_Prediction = confidenceInPrediction;
                }

                int Result::getIndexOfOneHotEncodedTargetSetToTrue() {
                    return 0;
                }
            } // Perception

        } // Network
    } // Elements
} // Results