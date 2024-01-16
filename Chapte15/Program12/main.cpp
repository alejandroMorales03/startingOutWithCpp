#include <iostream>
#include "/Users/alejandromorales/projects/Chapte15/Program12/ShipClas/Ship.h"
#include "/Users/alejandromorales/projects/Chapte15/Program12/CruiseShipClass/CruiseShip.h"
#include "/Users/alejandromorales/projects/Chapte15/Program12/CargoShipClass/CargoShip.h"


using namespace std;
int main(){

    std::string shipName;
    int year;
    int passengers;
    double weight;

    cout << "Enter a name of a ship: ";
    getline(cin,shipName);
    cout << "\nEnter the year that ship was built [1500 - Present]: ";
    cin >> year;
    cout << "\nIf this ship was a cruise ship, how many passengers could it carry: ";
    cin >> passengers;
    cout << "\nLastly, how much weight would it be able to carry in tons: ";
    cin >> weight;
    Ship* myShips[]={new Ship(shipName, year), new CruiseShip(shipName, year, passengers), new CargoShip(shipName, year, weight)};

    for(int index = 0; index < sizeof(myShips)/sizeof(myShips[0]); index++){
        myShips[index]->print();
    }
    
    return 0;
}