#include <iostream>

using namespace std;

bool inputValidation(float, float, float);
float getScores();
void avergCalc();

int main(){
    avergCalc();
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
        cout << "\nINVALID INPUT\n* Requirements\n  -Scores [0 - 100].\n\n";
    
    return valid;
}

/**
 * @param none
 * @return score
 * @brief Gathers the scores from the user, stores them in an array, and returns a pointer to the arrat.
*/

float getScores(){
    float score;
    do{
        cout << "Enter a score: ";
        cin >> score;
    }while(!inputValidation(score, 0, 100));
    
    return score;
    
}


/**
 * @param none
 * @return the average of all scores after dropping the lowest
 * @brief Gathers the scores from the user, until they stop, drops the lowest score, and finds the average of the remaining tests
*/
void avergCalc(){
    float running_t = 0;
    short tests = 0;
    char ext;
    short min = 100;
    float holder;

    do{
        holder = getScores();
        running_t += holder;
        if(holder < min)
            min = holder;
        cin.ignore();
        tests++;
        cout << "\nPress Q to finish. Anything else to keep entering scores: ";
        cin.get(ext);
    }while(tolower(ext) != 'q');

    running_t -= min;
    tests--;
    cout << "\nAverage: " << running_t / tests << "\n\n";
}