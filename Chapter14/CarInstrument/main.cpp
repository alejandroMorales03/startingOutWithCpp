#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

int main() {
    FuelGauge myCarGauge;

    std::cout << "\nTANK: " << myCarGauge.getGallons();

    while (myCarGauge.getGallons() < myCarGauge.getTankCapacity()) {
        std::cout << "\nGallons: " << myCarGauge.getGallons();
        myCarGauge++;
    }
    Odometer myCarOdo(myCarGauge);
    std::cout << "\nLet's go for a drive: ";

    for (int miles = 0; miles < 240; miles++) {
        ++myCarOdo;
    }

    std::cout << "\nMiles: " << myCarOdo.getCurrentMileage();
    std::cout << "\nGallons: " << myCarOdo.getGaugeInfo().getGallons();

    std::cout << "\n\n";

    return 0;
}
