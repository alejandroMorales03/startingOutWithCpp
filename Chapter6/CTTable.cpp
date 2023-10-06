#include <iostream>
#include <iomanip>

using namespace std;

float fahrenheitToCelsius(float);
void tablePrinter();

int main(){
    tablePrinter();
    return 0;

    
}

/**
 * @param float
 * @return The fahrenheit argument converted to Celsius
 * Description: Takes a fahrenehit value and converts it to celsius
*/

float fahrenheitToCelsius(float f_value){
    return (5/9.0) * (f_value - 32);
}

/**
 * @param float
 * @return void
 * Description: Prints a table of fahrenehit values and corresponding celsius values.
*/

void tablePrinter(){
    cout << "\nFahrenehit\tCelcius\n";
    cout << setprecision(2) << fixed;
    for(short index = 0; index <= 20; index++){
        cout << setw(4) << index << "\t\t" << setw(6) << fahrenheitToCelsius(index) << "\n";
    }
    cout << "\n";
}
