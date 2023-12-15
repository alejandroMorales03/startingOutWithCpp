#include "Die.h"
#include <iostream>

using namespace std;

int main(){
    bool contine = true;
    char check;
    Die myDie;

    do{
        cout << "\nLET'S FISH\n";
        cout << "\nFISHING...\n";
        myDie.Roll();
        cout << "\n" << myDie.checkCaught();
        cout << "\n\nPress e to exit and anything else to continue: ";
        cin >> check;

        if(toupper(check) == 'E')
            contine = false;

    }while(contine);

    cout << "\nPoints: " << myDie.getPoints() << "\n";
    cout << myDie.getMessage() << "\n\n";
    return 0;
}