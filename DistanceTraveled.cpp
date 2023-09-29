#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    float speed;
    short hours;
    do{
        cout << "\nEnter speed (mph): ";
        cin >> speed;
        cout << "Enter hours traveled: ";
        cin >> hours;
        if(speed < 0 || hours < 1)
            cout << "\nINVALID INPUT!\n* Hours must be at least 1\n* Speed can't be negative\n";
    }while(speed < 0 || hours < 1);

    cout << "\nHour\t\tDistance Traveled\n";
    for(short counter = 1; counter <= hours; counter++){
        cout << "\n" << setw(4) << counter << "\t\t" << setw(8) << speed * counter << " miles";
    }

    cout << "\n\n";

    return 0;
}