#include "Ticket.h"
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include <iostream>
#include <cmath>

Ticket::Ticket(ParkedCar aCar, ParkingMeter aMeter) : car(aCar) ,meter(aMeter){
    fine = 25;
  
}

double Ticket::getFine(){
    double timeDifference = car.getParkedTime() - meter.getPurchasedTime();

    fine += 10 * static_cast<int>(std::ceil(timeDifference / 15));

    return fine;
}

void Ticket::printTicket(){
    std::cout << "\nMake:                  " << car.getMake();
    std::cout << "\nModel:                 " << car.getModel();
    std::cout << "\nColor:                 " << car.getColor();
    std::cout << "\nLicense Number:        " << car.getLicNumber();
    std::cout << "\nTime Parked Illegally: " << car.getParkedTime() - meter.getPurchasedTime() << " minutes";
    std::cout << "\nFine: $                " << getFine() << "\n\n";
}