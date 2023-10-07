#include <iostream>
using namespace std;


bool inputValidation(float, float, float);
void getNumEmp(short&);
short getMissedDays(short);
float averageAbs(short, short);

int main(){

    short numEmp;
    getNumEmp(numEmp);
    short missedDays =  getMissedDays(numEmp);
    cout << "\nThe average absence was " << averageAbs(numEmp, missedDays) << " days.\n\n";
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
        cout << "\nINVALID INPUT\n* All data entered must be positive.\n";
    return valid;
}

/**
 * @param numEmp 
 * @return void
 * @brief Gets the number of employees working in the company and stores them in numEmp which is a ref variable
*/
 void getNumEmp(short& numEmp){
    
    do{
        cout << "\nHow many employees work at the company: ";
        cin >> numEmp;
    }while(!inputValidation(numEmp, 0, numEmp));
    if(numEmp == 0){
        cout << "\nSince there are no employees, the average absence was 0 days.\n\n";
        exit(0);
    }
}

/**
 * @param emp 
 * @return the total number of days missed
 * @brief Gets the total number of missed days by all employees and peforms inout validation before adding to the total
*/
short getMissedDays(short emp){
    short total_days = 0;
    short days = 0;
    for(short index = 0; index < emp; index++){
        do{
            cout << "\nEnter missed days for employee " << (index + 1) << ": ";
            cin >> days;
        }while(!inputValidation(days, 0, days));
        total_days += days;
    }
    return total_days;
}

/**
 * @param emp, days
 * @return average absency in the company
 * @brief Divides the total absent days over the total employees to get average absence
*/

float averageAbs(short emp, short days){
    return days/static_cast<float>(emp);
}