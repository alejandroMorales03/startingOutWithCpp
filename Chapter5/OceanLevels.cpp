#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    const float YEARLY_RISING_RATE = 1.5;
    const unsigned short YEARS = 25;
    
    cout << "\nYears from now\t\tMilimeters above current level\n";
    for(short counter = 1; counter <= 25; counter++){
        cout <<  setw(2) << counter << "\t\t\t\t" << setprecision(2) << fixed << setw(6) << counter* YEARLY_RISING_RATE << "\n";
    }
    cout  << "\n";
    return 0;
}