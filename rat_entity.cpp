#include "rat_entity.h"

RatEntity::RatEntity(std::string inputGender, std::string inputName, std::string inputDynasty) {
    gender = inputGender;
    givenName = inputName;
    dynastyName = inputDynasty;
    age = 0;
}

void RatEntity::addPups(std::shared_ptr<RatEntity> pup) {
    pups.push_back(pup);
    auto self = shared_from_this();
    if (self) {
        if (RatEntity::gender == "Male") {
            pup->father = self;
        }
        if (RatEntity::gender == "Female") {
            pup->mother = self;
        }
    }
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

std::string RatEntity::getRatFatherName() {
    return RatEntity::father;
}

std::string RatEntity::getRatMotherName() {
    return RatEntity::mother;
}