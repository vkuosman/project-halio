#ifndef RATENTITY_H
#define RATENTITY_H

#include <string>

class RatEntity {
    std::string gender;
    std::string givenName;
    std::string dynastyName;
    int age;
  public:
    RatEntity(std::string inputGender, std::string inputName, std::string inputDynasty);
    std::string getRatGender();
    std::string getRatName();
    std::string getRatDynasty();
};

#endif