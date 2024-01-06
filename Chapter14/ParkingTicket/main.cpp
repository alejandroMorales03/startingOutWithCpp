#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "Ticket.h"
#include "Officer.h"
#include <iostream>

using namespace std;

int main(){

    ParkedCar myCar("Nissan", "Altima", "White", "DZQP98");
    ParkingMeter meter(myCar, 30); 



    Officer policeOfficer("Gomez", 2309);
    
    if(policeOfficer.inspect(myCar, meter)){
       Ticket fine = policeOfficer.generateTicket(myCar, meter);
       fine.printTicket();
    }
    else{
        cout << "\nNot illegally parked";
    }

    return 0;

}

    