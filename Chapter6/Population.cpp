#include <iostream>
#include <iomanip>

using namespace std;

void populationEstimator();
bool inputValidation(float checkValue, float minValue, float maxValue);
long long migration();

int main(){
    populationEstimator();
    return 0;
}

/**
 * @param float,float,float
 * @return True/False Depending on whether "checkValue" is valid or not
 * @brief Checks checkValue against a max and min value to make sure checkValue is in range.
 * An error message is displayed if checkValue is out of range. Uses the var output to determine if it should print a clarifying prompt
*/

bool inputValidation(float checkValue, float minValue, float maxValue){
    bool valid = false;
    if(checkValue >= minValue && checkValue <= maxValue)
        valid = true;
    else{
        cout << "\nINVALID INPUT\n";
    }
    return valid;
}
/**
 * @brief Asks the user for input, performs input validation, and calculates population estimation
 * @param none
 * @return void
*/

void populationEstimator(){
    long long  initPop, years, migrationVar;
    float birthRate, deathRate;
    do{
        cout << "\nStarting population (Must be x >= 2): ";
        cin >> initPop;
        cout << "Birth Rate: [0 - 1]: ";
        cin >> birthRate;
        cout << "Death Rate: [0 - 1]: ";
        cin >> deathRate;
        cout << "Enter a number of years: [1 - INF) ";
        cin >> years;
    }while(!(inputValidation(initPop, 2, initPop) && inputValidation(birthRate, 0, 1) 
            && inputValidation(deathRate, 0, 1) && inputValidation(years, 1, years)));
            migrationVar = migration();
    for(short index = 1; index <= years; index++){
        initPop = static_cast<long>(initPop + birthRate * initPop - deathRate * initPop + migrationVar);
        if(initPop < 0)
            initPop = 0;
        cout << "\nIn " << setw(2) << index << " years the opulation wil be " << initPop;

    }
    cout << "\n\n";
}

/**
 * @brief Asks the user for input, performs input validation, and calculates migration
 * @param none
 * @return returns the difference between migration and inmigration
*/
long long migration(){
    long long in, out;
    do{
        cout << "\nHow many people usually migrate out of this area: ";
        cin >> out;
        cout << "How many people inmigrate to this area: ";
        cin >> in;
    }while(!(inputValidation(out, 0, out) && inputValidation(in, 0, in)));
    return in - out;

}