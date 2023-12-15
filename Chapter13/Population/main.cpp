#include "population.h"
#include <iostream>
using namespace std;

int main(){
    int size, births, deaths;
    cout << "\nEnter a population number: ";
    cin >> size;

    cout << "\nEnter a numebr of births: ";
    cin >> births;

    cout << "\nEnter a number of deaths: ";
    cin >> deaths;

    population myPop(size, births, deaths);
    cout << "\nBirth Rate: " << myPop.getBirthR();
    cout << "\nDeath Rate: " << myPop.getDeathR() << "\n\n";
}