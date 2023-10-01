#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    const float MIN_CEL = 0, MAX_CEL = 20;

    cout << "Celsius\t\tFahrenheit";
    for(short c_temp = MIN_CEL; c_temp <= MAX_CEL; c_temp++){
        cout << "\n" << setw(2) << c_temp << "\t\t\t" << setw(4) << (c_temp * 9/5.0 + 32);
    }
    cout << "\n\n";
    return 0;
}