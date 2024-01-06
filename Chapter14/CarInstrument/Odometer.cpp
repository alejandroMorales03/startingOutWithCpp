#include "Odometer.h"
#include <iostream>

Odometer::Odometer(FuelGauge gauge) : thisCarGauge(gauge), currentMileage(0) {}

float Odometer::getCurrentMileage() const {
    return currentMileage;
}

Odometer Odometer::operator++() {
    if (currentMileage == MAX_MILEAGE)
        currentMileage = 0;
    else
        currentMileage++;

    // Adjust fuel based on car's efficiency (CAR_ECONOMY)
    if (static_cast<int>(currentMileage) % CAR_ECONOMY == 0) {
        --thisCarGauge;
    }

    return *this;
}

Odometer Odometer::operator++(int) {
    Odometer temp = *this;
    if (this->currentMileage == MAX_MILEAGE)
        this->currentMileage = 0;
    else
        this->currentMileage++;

    // Adjust fuel based on car's efficiency (CAR_ECONOMY)
    if (static_cast<int>(currentMileage) % CAR_ECONOMY == 0) {
        --thisCarGauge;
    }

    return temp;
}

FuelGauge Odometer::getGaugeInfo(){
    return thisCarGauge;
}
