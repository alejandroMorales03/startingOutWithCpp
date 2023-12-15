#include "Narray.h"
#include <iostream>

using namespace std;
int main(){

    Narray myNarray(5);
    myNarray.StoreElmnt(0, 100);
    cout << "\nElement 0: " << myNarray.getElmnt(0);
    cout << "\nAverage: " << myNarray.getAverage();
    cout << "\nHighest: " << myNarray.getHighest();
    cout << "\nLowest: " << myNarray.getlowest() << "\n";
    myNarray.StoreElmnt(5, 100);
    cout << "\nError: " << myNarray.getElmnt(5) << "\n\n";
    
    return 0;
}