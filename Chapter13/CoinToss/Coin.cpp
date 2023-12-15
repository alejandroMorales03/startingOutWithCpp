#include "Coin.h"
#include <ctime>
#include <cstdlib>

Coin::Coin(){
    srand(time(0));
    toss();
}

void Coin::toss(){
    sideUp = (rand() % (1 - 0 + 1) + 0) == 0? "tails" : "heads";

}

string Coin::getSideUp(){
    return sideUp;
}