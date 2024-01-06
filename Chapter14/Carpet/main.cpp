#include "RoomCarpet.h"
#include <iostream>

using namespace std;

int main(){
    FeetInches length;
    FeetInches width;

    int lengthFeet, lengthInches, widthFeet, widthInches;

    cout << "\nFor the length: ";
    cout << "\nEnter feet: ";
    cin >> lengthFeet;
    cout << "Enter inches: ";
    cin >> lengthInches;


    cout << "\nFor the width: ";
    cout << "\nEnter feet: ";
    cin >> widthFeet;
    cout << "Enter inches: ";
    cin >> widthInches;

    cout << "\nWhats the price per quared feet: ";
    double price;
    cin >> price;

    RoomCarpet myRooom(lengthFeet, lengthInches, widthFeet, widthInches, price);

    cout << "Total $: " << myRooom.getTotal() << "\n";
    return 0;
}
