#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer{
    private:
        static const long MAX_MILEAGE = 999999;
        static const int CAR_ECONOMY = 24;
        float currentMileage;
        FuelGauge thisCarGauge;

    public:
        Odometer(FuelGauge gauge);
        float getCurrentMileage()const;
        FuelGauge getGaugeInfo();

        Odometer operator++();
        Odometer operator++(int);
    


};

#endif