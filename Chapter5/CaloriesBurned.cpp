#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    const float BURNED_CAL_MIN = 3.6;
    const unsigned short UPDATE_VALUE = 5, MAX_CHECK_VALUE = 30;

    for(short minutes = 5; minutes < MAX_CHECK_VALUE; minutes += UPDATE_VALUE){
        cout << "\nAfter " << setw(2) <<  minutes << " minutes " << setw(5) << minutes * BURNED_CAL_MIN << " were burned";
    }
    cout << "\n\n";
    return 0;
}