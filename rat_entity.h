#ifndef RATENTITY_H
#define RATENTITY_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Inherit from std::enable_shared_from_this<RatEntity>
class RatEntity : public std::enable_shared_from_this<RatEntity> {
    int age;
    std::string gender;
    std::vector<std::shared_ptr<RatEntity>> pups;
    std::weak_ptr<RatEntity> father;
    std::weak_ptr<RatEntity> mother;
    std::string givenName;
    std::string dynastyName;
  public:
    RatEntity(std::string inputGender, std::string inputName, std::string inputDynasty);
    void addPups(std::shared_ptr<RatEntity>);
    std::string getRatGender();
    std::string getRatName();
    std::string getRatDynasty();
    std::string getRatFatherName();
    std::string getRatMotherName();
};

#endif