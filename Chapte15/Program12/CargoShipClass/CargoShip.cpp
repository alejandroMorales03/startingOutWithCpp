#include "CargoShip.h"

CargoShip::CargoShip(std::string name, int year, double capacity) : Ship(name, year){
    setTonCapacity(capacity);


}
void CargoShip::setTonCapacity(double tons){
    if(tons < 0)
        throw std::runtime_error("ERROR TYPE| NEGATIVE CAPACITY IS INVALID");
    tonCap = tons;
}

double CargoShip::getTonCapacity()const{return tonCap;}

void CargoShip::print(){
    std::cout << "\n" << "Cargo Ship " <<getName() << ", " << tonCap << " tons";
}

CargoShip::~CargoShip(){}