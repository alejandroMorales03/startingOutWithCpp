#include <iostream>

using namespace std;
const short REGIONS = 5;

void getNumAccidents(const string*, short*);
short findLowest(short*);
bool inputValidation(float, float, float);

int main(){

    const string regions[] = {"North", "South", "East", "West", "Central"};
    short num_accidents[REGIONS];

    getNumAccidents(regions, num_accidents);
    cout << "\nThe safest region is the " << regions[findLowest(num_accidents)] << " region";
    return 0;
}

/**
 * @param string, float 
 * @return none
 * Description: The function takes the address to a string array and a short array and populates the acc_arg array with user data
*/

void getNumAccidents(const string* region_arg, short* acc_arg){
    cout << "\n";
    for(short index = 0;  index < REGIONS; index++){
        do{
            cout << "Enter the number of accidents reported in the " << region_arg[index] << ": ";
            cin >> acc_arg[index];
        }while(!inputValidation(acc_arg[index], 0, acc_arg[index]));
    }
}

/**
 * @param acc_arg
 * @return The index corresponding to the minimum value
 * Description: Finds the lowest value in an array and returns its corresponding index.
*/

short findLowest(short* acc_arg){
    short lowest = acc_arg[0];
    short min_index = 0;

    for(short index = 0; index < REGIONS; index++){
        if(acc_arg[index] < lowest){
            lowest = acc_arg[index];
            min_index = index;
        }
    }
    return min_index;
}

/**
 * @param float,float,float
 * @return True/False Depending on whether "checkValue" is valid or not
 * Description: Checks checkValue against a max and min value to make sure checkValue is in range.
 * An error message is displayed if checkValue is out of range.
*/

bool inputValidation(float checkValue, float minValue, float maxValue){
    bool valid = false;
    if(checkValue >= minValue && checkValue <= maxValue)
        valid = true;
    else
        cout << "\nINVALID INPUT\n* All data entered must be positive.\n\n";
    
    return valid;
}