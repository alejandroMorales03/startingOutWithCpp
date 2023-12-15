#include "Coin.h"
#include <iostream>
using namespace std;

int main(){
    Coin myCoin;
    cout << "\nFace up: " << myCoin.getSideUp();

    cout << "\nFlipping 20 times\n\n";

    const string HEADS = "heads", TAILS = "tails";
    string toss_result;
    int heads = 0, tails = 0;

    for(short counter = 0; counter < 20; counter++){
        myCoin.toss();
        toss_result = myCoin.getSideUp();

        cout << "\nFace up: " << toss_result;

        if(toss_result == HEADS)
            heads++;
        else
            tails++;
    }

    cout << "\nNumber of heads: " << heads;
    cout << "\nNumber of tails: " << tails;
    return 0;
}