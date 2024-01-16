#include "CruiseShip.h"

CruiseShip::CruiseShip(std::string name, int year, int passengers) : Ship(name, year){
    setMaxPassengers(passengers);

}


void CruiseShip::setMaxPassengers(int passengers){
    if(passengers < 0)
        throw std::runtime_error("ERROR TYPE| PASSENGERS CANNOT BE NEGATIVE");
    maxPassengers = passengers;
}

void CruiseShip::print(){
    std::cout << "\n" << "Cruise Ship " << getName() << ", " << maxPassengers << " passengers";
}
int CruiseShip::getMaxpassengers()const{return maxPassengers;}
CruiseShip::~CruiseShip(){}