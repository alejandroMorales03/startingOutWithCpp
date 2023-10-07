#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool inputValidation(float, float, float);
short getComputerChoice();
int main(){
    short computerChoice = getComputerChoice(), userChoice;
    do{
        cout << "Choose\n\n1. Rock\n2. Paper\n3. Scissors\n\nChoice: ";
        cin >> userChoice;
    }while(!inputValidation(userChoice, 1, 3));

    string words[] = {"rock", "paper", "scissors"};

    cout << "\nComputer: " << words[computerChoice - 1];
    cout << "\nUser:     " << words[userChoice - 1];

    if(computerChoice == 3 && userChoice == 1) computerChoice = 0;
    else if(computerChoice == 1 && userChoice == 3) userChoice = 0;

    if(userChoice > computerChoice)
        cout << "\nUser wins!!";
    else if(userChoice < computerChoice)
        cout << "\nComputer wins!!";
    else
        cout << "\nTie!!";
    cout << "\n\n"; 


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
        cout << "\nINVALID INPUT\n* Enter only 1 through 3.\n\n";
    
    return valid;
}

/**
 * @brief Generates a random number between 1 and 3
 * @param none
 * @return the random number generated
*/

short getComputerChoice(){
    srand(time(0));
    return (rand() % (3 - 1 + 1) + 1);
}
