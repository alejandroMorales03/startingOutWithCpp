#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    short user_input, corr_ans, guessCount = 0;
    srand(time(0));
    corr_ans = (rand() % (1000 - 1 + 1)) + 1;

    do{
        cout << "\nGuess the number (1 - 1000): ";
        cin >> user_input;

        if(user_input > corr_ans)
            cout << "\nLower!\n";
        else if(user_input < corr_ans)
            cout << "\nHigher!\n";
        guessCount++;
    }while(user_input != corr_ans);

    cout << "\nCongratulations. " << corr_ans << " was the number. It took you " << guessCount << " guesses\n\n";
    return 0;
}