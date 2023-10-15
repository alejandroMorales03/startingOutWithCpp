#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateLotteryNumber(short[]);
void getUserNumber(short[]);
bool inputVal(float, float, float );
short getMatch(short[], short[]);

int main(){
    short lottoNumber[5];
    generateLotteryNumber(lottoNumber);
    short userNumber[5];
    getUserNumber(userNumber);
    short match = getMatch(lottoNumber, userNumber);
    if(match < 5)
        cout << "\n" << match << " digits match\n\n";
    else
        cout << "\nWINNER WINNER CHICKEN DINNER\n\n";

}

/**
 * @brief generates lottery number with random generator
 * 
 * @param lotto 
 */
void generateLotteryNumber(short lotto[]){
    srand(time(0));
    for(short index = 0; index < 5; index++){
        lotto[index] = (rand() % (9 - 0 + 1) + 0);
    }
}

/**
 * @brief Get the User Number object
 * 
 * @param user 
 */
void getUserNumber(short user[]){
    cout << "\nEnter your digits separated by spaces: ";
    for(short index = 0; index < 5; index++){
       do{
        cin >> user[index];
    }while(!inputVal(user[index], 0, 9));

    }
}

/**
 * @brief Checks if user info is within a given range
 * 
 * @param check 
 * @param min 
 * @param max 
 * @return true 
 * @return false 
 */
bool inputVal(float check, float min, float max){
    if(check >= min && check <= max)
        return true;
    else{
        cout << "\nERROR: MUST BE SINGLE DIGIT\n\n";
        return false;
    }
}

short getMatch(short winning[], short user[]){
    short match = 0;
    for(short index = 0; index < 5; index++){
        if(winning[index] == user[index])
            match++;
    }
    return match;
}
