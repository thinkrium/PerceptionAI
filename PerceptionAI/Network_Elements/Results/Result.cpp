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

                Perception_Element_Vector<Perception_Element> & Result::getOneHotEncodedTargets() {

                    try {

                        if(!this->isOneHotEncodedTargetsAreSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }
                        return One_Hot_Encoded_Targets;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }

                    return One_Hot_Encoded_Targets;
                }

                void Result::setOneHotEncodedTargets(
                        const Perception_Element_Vector<Perception_Element> &oneHotEncodedTargets) {
                    One_Hot_Encoded_Targets = oneHotEncodedTargets;

                    this->setOneHotEncodedTargetsAreSet(true);

                }

                int Result::getOneHotEncodedTargetsCount() {
                    try {

                        if(!this->isOneHotEncodedTargetsCountIsSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }
                        return One_Hot_Encoded_Targets_Count;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }


                    return One_Hot_Encoded_Targets_Count;
                }

                void Result::setOneHotEncodedTargetsCount(int oneHotEncodedTargetsCount) {
                    One_Hot_Encoded_Targets_Count = oneHotEncodedTargetsCount;
                    this->setOneHotEncodedTargetsCountIsSet(true);
                }

                float Result::getTotalLoss() {

                    try {

                        if(!this->isTotalLossesAreSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }
                        return Total_Loss;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }


                    return Total_Loss;
                }

                void Result::setTotalLoss(float totalLoss) {

                    Total_Loss = totalLoss;
                    this->setTotalLossesAreSet(true);
                }

                const Perception_Element_Vector<Perception_Element> &Result::getLosses() {
                    try {

                        if(!this->isLossesAreSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }
                        return Losses;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }


                    return Losses;
                }

                void Result::setLosses(const Perception_Element_Vector<Perception_Element> &losses) {
                    Losses = losses;
                    this->setLossesAreSet(true);
                }

                float Result::getConfidenceInPrediction() {
                    try {

                        if(!this->isConfidenceInPredictionIsSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }
                        return Confidence_In_Prediction;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }


                    return Confidence_In_Prediction;
                }

                void Result::setConfidenceInPrediction(float confidenceInPrediction) {
                    Confidence_In_Prediction = confidenceInPrediction;
                    this->setConfidenceInPredictionIsSet(true);
                }

                int Result::getIndexOfOneHotEncodedTargetSetToTrue() {
                    try {

                        if(!this->isOneHotEncodedTargetsAreSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }

                        int correctIndex = 0;

                        int iteratingIndex = 0;

                        for(Perception_Element element : this->getOneHotEncodedTargets().getElementVector()) {
                            if(element.getValue() == 1);
                            correctIndex = iteratingIndex;
                            iteratingIndex++;
                        }

                        return correctIndex;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }


                    return -1;
                }

                const Perception_Element_Vector<Perception_Element> &Result::getLossDerivatives() {
                    try {

                        if(!this->isLosseDerivativesAreSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }
                        return Loss_Derivatives;
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }


                    return Loss_Derivatives;
                }

                void Result::setLossDerivatives(const Perception_Element_Vector<Perception_Element> &lossDerivatives) {
                    Loss_Derivatives = lossDerivatives;
                    this->setLosseDerivativesAreSet(true);
                }

                void Result::addLossDerivativeToLossDerivatives(Perception_Element lossDerivative) {
                    try {

                        if(!this->isLosseDerivativesAreSet()) { throw runtime_error(Perception_Enumerations::errorMessages::Object_Exists_But_No_Derived_Value_Set); }
                        this->Loss_Derivatives.getElementVector().push_back(lossDerivative);
                    }
                    catch (exception e) {
                        this->setHealthStatus(Perception_Enumerations::healthStatus::error);
                        this->addErrorMessage(e.what());
                    }

                }

                bool Result::isOneHotEncodedTargetsAreSet() const {
                    return oneHotEncodedTargetsAreSet;
                }

                void Result::setOneHotEncodedTargetsAreSet(bool oneHotEncodedTargetsAreSet) {
                    Result::oneHotEncodedTargetsAreSet = oneHotEncodedTargetsAreSet;
                }

                bool Result::isOneHotEncodedTargetsCountIsSet() const {
                    return oneHotEncodedTargetsCountIsSet;
                }

                void Result::setOneHotEncodedTargetsCountIsSet(bool oneHotEncodedTargetsCountIsSet) {
                    Result::oneHotEncodedTargetsCountIsSet = oneHotEncodedTargetsCountIsSet;
                }

                bool Result::isTotalLossesAreSet() const {
                    return totalLossesAreSet;
                }

                void Result::setTotalLossesAreSet(bool totalLossesAreSet) {
                    Result::totalLossesAreSet = totalLossesAreSet;
                }

                bool Result::isLossesAreSet() const {
                    return lossesAreSet;
                }

                void Result::setLossesAreSet(bool lossesAreSet) {
                    Result::lossesAreSet = lossesAreSet;
                }

                bool Result::isLosseDerivativesAreSet() const {
                    return losseDerivativesAreSet;
                }

                void Result::setLosseDerivativesAreSet(bool losseDerivativesAreSet) {
                    Result::losseDerivativesAreSet = losseDerivativesAreSet;
                }

                Result::Result() {}

                bool Result::isConfidenceInPredictionIsSet() const {
                    return confidenceInPredictionIsSet;
                }

                void Result::setConfidenceInPredictionIsSet(bool confidenceInPredictionIsSet) {
                    Result::confidenceInPredictionIsSet = confidenceInPredictionIsSet;
                }
            } // Perception

        } // Network
    } // Elements
} // Results