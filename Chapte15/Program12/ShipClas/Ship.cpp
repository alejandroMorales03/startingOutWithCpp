#include "Ship.h"
#include "chrono"
#include <ctime>
#include <iostream>

int Ship::MIN_YEAR = 1500;

Ship::Ship(std::string name, int year){
    setName(name);

    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;


    if(year < MIN_YEAR || year > currentYear)
        throw std::runtime_error("ERROR TYPE| INVALID YEAR [1500 - " + std::to_string(currentYear) + "]");
    setYear(year);
}
        
void Ship::setName(std::string name){
    shipName = name;

}
void Ship::setYear(int year){
    yearBuilt = year;
}

std::string Ship::getName(){return shipName;}
int Ship::getYear(){return yearBuilt;}

void Ship::print(){
    std::cout << "\n" << "Ship " << shipName << ", " << yearBuilt;
}

Ship::~Ship(){}