#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    short starting_population, period;
    float growth_rate;

    do{
        cout << "\nEnter starting population size: ";
        cin >> starting_population;
        cout << "Enter average multiplication rate as a percentage (0 - 100 %): ";
        cin >> growth_rate;
        cout << "Enter how mnany days you want to study the population: ";
        cin >> period;

        if(starting_population < 2 || growth_rate < 0 || period < 1){
            cout << "\nINVALID INPUT!\n* Population must be at least 2\n* Multiplication rate must be 0 - 100 %\n*";
            cout << "The length of the study must be at least 1 day\n";
        }

    }while(starting_population < 2 || growth_rate < 0 || period < 1);

    growth_rate = growth_rate >= 100? growth_rate : growth_rate + 100;

    cout << "\nDay\t\t\tPopulation Size";
    for(short c_day = 1; c_day <= period; c_day++){
        cout << "\n" << setw(4) << c_day << "\t\t" << setw(10) << static_cast<int>(starting_population * pow((growth_rate/100), c_day)); 
    }

    cout << "\n\n";
    return 0;

}