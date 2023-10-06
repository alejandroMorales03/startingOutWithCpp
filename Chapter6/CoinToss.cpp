#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool inputValidation(float,float, float ); 
short getTimes();
void flipCoin(short);
int main(){

    flipCoin(getTimes());

    return 0;
}

/**
 * @param float,float,float
 * @return True/False Depending on whether "checkValue" is valid or not
 * @brief Checks checkValue against a max and min value to make sure checkValue is in range.
 * An error message is displayed if checkValue is out of range.
*/
bool inputValidation(float checkValue, float minValue, float maxValue){
    bool valid = false;
    if(checkValue >= minValue && checkValue <= maxValue)
        valid = true;
    else
        cout << "\nINVALID INPUT\n* Flip the coin at least once.\n";
    
    return valid;
}

/**
 * @param none
 * @return Number of flips to be performed
 * @brief Gets the number of times an user wants to flip a coin
*/
short getTimes(){
    short flips;
    do{
        cout << "\nHow many times should the coin be flipped: ";
        cin >> flips;
    }while(!inputValidation(flips, 0, flips));
    return flips;
}


/**
 * @param flips
 * @return void
 * @brief Generates random numbers between one and two to decide whether the coin will land on heads or tails;
*/
void flipCoin(short flips){
    srand(time(0));
    for(short index = 0; index < flips; index++){
        cout << "\nFlipping the Coin...\n";
        if((rand() % (2 - 1 + 1) + 1) == 2)
            cout << "HEADS";
        else
            cout << "TAILS";
    }
    cout << "\n\n";
}
  