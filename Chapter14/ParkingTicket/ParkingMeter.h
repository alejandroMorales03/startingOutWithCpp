#ifndef PARKINGMETER_H
#define PARKINGMETER_H

#include "ParkedCar.h"

class ParkingMeter{
    private:
        double timePurchased;
        ParkedCar car;

    public:
        ParkingMeter(ParkedCar, double);
        ParkingMeter();

        void confirmationMessage(const ParkedCar&);
        double getPurchasedTime() const;

};

#endif