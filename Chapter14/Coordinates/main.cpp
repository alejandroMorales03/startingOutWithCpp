#include <iostream>
#include "Coordinates.h"

using namespace std;

int main(){
    Coordinates myLocation;
    Coordinates myDestination(90, 180);
    Coordinates yourDestination(myDestination);

    myLocation.printCoordinates('\n');
    myDestination.printCoordinates('\n');
    yourDestination.printCoordinates('\n');
    cout << (myDestination <= myLocation) << "\n";
    cout << (myDestination != myLocation) << "\n";
    (myDestination * myLocation).printCoordinates();
    cout  << "\n\n";
    return 0;

}