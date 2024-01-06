#include "FuelGauge.h"
#include <iostream>

FuelGauge::FuelGauge(float gallons) : gallonsInTank(gallons > 15 ? 15 : gallons) {}

float FuelGauge::getGallons() const {
    return gallonsInTank;
}

float FuelGauge::getTankCapacity() const {
    return MAX_GALLONS;
}

void FuelGauge::tankStatusNotice() {
    if (gallonsInTank == MAX_GALLONS)
        std::cout << "\nTANK IS AT MAX CAPACITY: " << MAX_GALLONS << " GALLONS\n";
    if (gallonsInTank == 0)
        std::cout << "\nTANK IS EMPTY\n";
}

FuelGauge FuelGauge::operator++() {
    if (gallonsInTank < MAX_GALLONS)
        gallonsInTank++;
    tankStatusNotice();
    return *this;
}

FuelGauge FuelGauge::operator++(int) {
    FuelGauge temp = *this;
    if (gallonsInTank < MAX_GALLONS)
        gallonsInTank++;
    tankStatusNotice();
    return temp;
}

FuelGauge FuelGauge::operator--() {
    if (gallonsInTank > 0)
        gallonsInTank--;
    tankStatusNotice();
    return *this;
}

FuelGauge FuelGauge::operator--(int) {
    FuelGauge temp = *this;
    if (gallonsInTank > 0)
        gallonsInTank--;
    tankStatusNotice();
    return temp;
}
