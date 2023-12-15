#include "/Users/alejandromorales/projects/Chapter13/Fishing/Die.h"
#include <iostream>

using namespace std;

int main(){
    Die die_one, die_two;

    int computer_score = 0, user_score = 0, answer;
    const int MAX = 21;
    bool keepGoing = false;

    do{
        computer_score += die_one.Roll() + die_two.Roll();

        cout << "\nPRESS ANY KEY TO ROLL YOUR DIES: ";
        cin.get();

        answer = die_one.Roll();
        user_score += answer;
        cout << "\n" << answer;
        
        answer = die_two.Roll();
        user_score += answer;
        cout << " " << answer << "\n";

        cout << "\nWant to keep rolling: \n\n1. Yes\n2. No\n\n";
        cout << "Selection: ";
        cin >> answer;
        
        if(answer == 1)
            keepGoing = true;
        else
            keepGoing = false;

        cin.ignore();

    }while(user_score < 21 && keepGoing);

    cout << (user_score > 21 || user_score < computer_score? "\nYou Lose! Computer score was " + to_string(computer_score) :  
             "YOU WIN!") << "\n\n";
    return 0;
}