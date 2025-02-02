// Your First C++ Program

//INTRO
#include <iostream>
#include <string>
#include <thread>
#include <chrono>


// RAT CLASS
#include "rat_entity.h"


// RAT GENERATION
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include<ctime>


// INTRO
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

void playIntro() {
    std::cout << "." << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
    std::cout << ".." << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
    std::cout << "..." << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
    std::cout << "Forgotten in the test chambers of The National Institute of General Heredity Transfusing..." << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(3000));
    std::cout << "A ceaseless struggle to game the \"behavioral sink\"..." << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(3000));
    std::cout << "But in the end only a single dynasty shall breed the..." << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(3000));
    std::cout << YELLOW << ".____          ___.     __________         __     ____  __.__                " << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    std::cout << "|    |   _____ \\_ |__   \\______   \\_____ _/  |_  |    |/ _|__| ____    ____  " << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    std::cout << "|    |   \\__  \\ | __ \\   |       _/\\__  \\    __\\ |      < |  |/    \\  / ___\\ " << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    std::cout << "|    |___ / __ \\| \\_\\ \\  |    |   \\ / __ \\|  |   |    |  \\|  |   |  \\/ /_/  >" << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    std::cout << "|_______ (____  /___  /  |____|_  /(____  /__|   |____|__ \\__|___|  /\\___  / " << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    std::cout << "        \\/    \\/    \\/          \\/      \\/               \\/       \\//_____/  " << RESET << std::endl;
    std::cout << std::endl;
}

void testRatClass() {
    std::cout << "\nDEBUG: TESTING RAT CREATION...\n" << std::endl;
    std::string userNameInput{"Default"};
    std::string userDynastyInput{"Default"};
    std::string userGenderInput{"Default"};
    std::cout << "Type rat gender: ";
    std::getline(std::cin, userGenderInput);
    std::cout << "Type rat name: ";
    std::getline(std::cin, userNameInput);
    std::cout << "Type rat dynasty: ";
    std::getline(std::cin, userDynastyInput);
    RatEntity testRat(userGenderInput, userNameInput, userDynastyInput);
    std::cout << "\nRat gender: " << testRat.getRatGender() << std::endl;
    std::cout << "Rat name: " << testRat.getRatName() << std::endl;
    std::cout << "Rat dynasty name: " << testRat.getRatDynasty() << std::endl;
}

void testRatGeneration() {
    srand(time(0));
    std::vector<std::string> nameVector;
    std::vector<std::string> dynastyVector;
    int randomNumber{0};
    std::ifstream readNameFile("assets/names/default_m_first_names.txt");
    std::copy(std::istream_iterator<std::string>(readNameFile), std::istream_iterator<std::string>(), std::back_inserter(nameVector));
    std::cout << "1: " << nameVector.size() << std::endl;
    std::cout << "2: " << rand() << std::endl;
    int randomNameNum = 1 + rand() % nameVector.size();
    std::ifstream readDynastyFile("assets/names/default_dynasty_names.txt");
    std::copy(std::istream_iterator<std::string>(readDynastyFile), std::istream_iterator<std::string>(), std::back_inserter(dynastyVector));
    int randomDynastyNum = 1 + rand() % dynastyVector.size();
    //  TODO: Implement random gender
    RatEntity testRat("male", nameVector[randomNameNum - 1], dynastyVector[randomDynastyNum - 1]);
    std::cout << "Rat name: " << testRat.getRatName() << std::endl;
    std::cout << "Rat dynasty name: " << testRat.getRatDynasty() << std::endl;
}

void testHelp() {
    std::cout << "\nList of possible inputs:\n" << std::endl;
    std::cout << "debug create rat" << std::endl;
    std::cout << "debug generate rat" << std::endl;
    std::cout << "debug help" << std::endl;
    std::cout << "exit game" << std::endl;
}

bool doInputAction(std::string action) {
    if (action == "debug create rat") {
        testRatClass();
        return true;
    } else if  (action == "debug generate rat") {
        testRatGeneration();
        return true;
    } else if  (action == "debug help") {
        testHelp();
        return true;
    } else if  (action == "exit game") {
        return false;
    } else {
        std::cout << "Incorrect action." << std::endl;
        return true;
    };
}

int main() {
    //playIntro();
    std::string userInput{"Default"};
    bool gameContinues{true};
    while (gameContinues) {
        std::cout << "\nType an input: ";
        std::getline(std::cin, userInput);
        gameContinues = doInputAction(userInput);
    }
    return 0;
}
