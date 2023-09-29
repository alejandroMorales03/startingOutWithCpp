#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    const float CURRENT_PRICE = 2500, INCREASED_RATE = 1.04, YEARS = 6;

    cout << "\nYears from Now\t\tProjected Rate\n";

    for(short counter = 1; counter <= YEARS; counter++){
        cout << "\n" << setw(7) << counter << "\t\t\t" << setprecision(3) << fixed << setw(12) << CURRENT_PRICE * pow(INCREASED_RATE, counter);
    }
    cout << "\n\n";
    return 0;
}