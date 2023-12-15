#include "Car.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    Car myCar(2015, "Mazda");

    cout << "\n" << myCar.getMake() << " " << myCar.getYearModel() << "\n";

    for(short counter = 0; counter < 5; counter++){
        myCar.accelerate();
        cout << "\nSpeed: " <<  setw(2) << myCar.getSpeed() << " mph";
    }
    cout << "\n";
    for(short counter = 0; counter < 6; counter++){
        myCar.brake();
        cout << "\nSpeed: " << setw(2) << myCar.getSpeed() << " mph";
    }
    cout << "\n"; 

    
    return 0;
}