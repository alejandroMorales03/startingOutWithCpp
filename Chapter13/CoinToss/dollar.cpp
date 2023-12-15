#include "Coin.h"
#include <iostream>

int main(){
    Coin quarter, dime, nickel;

    float balance = 0;

    cout << "\nPress any key to start playing: ";
    cin.get();

    while(balance < 1){
        cout << "\nTOSSING COINS...\n";
        quarter.toss();
        dime.toss();
        nickel.toss();

        if(quarter.getSideUp() == "heads"){
            balance += .25;
            cout << "\n+.25";
        }
        if(dime.getSideUp() == "heads"){
            balance += .10;
            cout << "\n+.10";
        }
        if(nickel.getSideUp() == "heads"){
            balance += .05;
            cout << "\n+.05";
        }
        cout << "\nBalance: " << balance;
        cout << "\n\nPress any key to continue: ";
        cin.get();
    }

    if(balance == 1)
        cout << "\nYOU WIN\n\n";
    else
        cout << "\nYOU LOSE\n\n";
    return 0;
}