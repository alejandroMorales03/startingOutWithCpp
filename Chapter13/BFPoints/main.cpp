#include "BFPoints.h"
#include <iostream>

using namespace std;

int main(){

    BFPoints temp_1(200);
    float temp;
    cout << "\nEnter a temperature: ";
    cin >> temp;

    BFPoints temp_2;
    temp_2.setTemp(temp);

    cout << "\n" << temp_1.getTemp();
    cout << "\n" << "ETHYL FREEZING:  " << temp_1.isEthylFreezing();
    cout << "\n" << "ETHYL BOILING:   " << temp_1.isEthylBoining();
    cout << "\n" << "OXYGEN FREEZING: " << temp_1.isOxyFreezing();
    cout << "\n" << "OXYGEN BOILING:  " << temp_1.isOxyBoiling();
    cout << "\n" << "WATER FREEZING:  " << temp_1.isWatFreezing();
    cout << "\n" << "WATER BOILING:   " << temp_1.isWatBoiling();

    cout << "\n\n" << temp_2.getTemp();
    cout << "\n" << "ETHYL FREEZING:  " << temp_2.isEthylFreezing();
    cout << "\n" << "ETHYL BOILING:   " << temp_2.isEthylBoining();
    cout << "\n" << "OXYGEN FREEZING: " << temp_2.isOxyFreezing();
    cout << "\n" << "OXYGEN BOILING:  " << temp_2.isOxyBoiling();
    cout << "\n" << "WATER FREEZING:  " << temp_2.isWatFreezing();
    cout << "\n" << "WATER BOILING:   " << temp_2.isWatBoiling() << "\n\n";

    return 0;
}