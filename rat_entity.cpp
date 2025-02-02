#include "rat_entity.h"

RatEntity::RatEntity(std::string inputGender, std::string inputName, std::string inputDynasty) {
    gender = inputGender;
    givenName = inputName;
    dynastyName = inputDynasty;
    age = 0;
}

std::string RatEntity::getRatGender() {
    return RatEntity::gender;
}

std::string RatEntity::getRatName() {
    return RatEntity::givenName;
}

std::string RatEntity::getRatDynasty() {
    return RatEntity::dynastyName;
}