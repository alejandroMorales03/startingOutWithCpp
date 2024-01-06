#include "FeetInches.h"
#include <iostream>

using namespace std;

int main(){

    FeetInches measureOne;
    FeetInches measurementTwo;

    cin >> measureOne;
    cin >> measurementTwo;
    
    measureOne.printMeasurement("\n\n");
    measurementTwo.printMeasurement("\n\n");

    (measureOne * measurementTwo).printMeasurement("\n\n");
    cout << (measureOne * measurementTwo) << "\n\n";    


    return 0;
}