#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(ParkedCar parkedCar, double timeMinutes) : car(parkedCar){
    timePurchased = timeMinutes;
    confirmationMessage(car);
}

ParkingMeter::ParkingMeter(){
    std::cout << "\nMISSING ARGUMENTS 1";
    exit(0);
}

void ParkingMeter::confirmationMessage(const ParkedCar& thisCar){
    std::cout << "\n" << thisCar.getColor() << " " << thisCar.getMake() << " " << thisCar.getModel();
    std::cout << " with License Number " << thisCar.getLicNumber() << ": " << timePurchased << " minutes purchased.";
}

double ParkingMeter::getPurchasedTime()const{
    return timePurchased;
}