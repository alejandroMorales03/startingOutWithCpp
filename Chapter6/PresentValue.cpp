#include <iostream>
#include <cmath>

using namespace std;
void getData();
bool inputValidation(float, float, float);
float calculatePresentValue(float, float, short); 

int main(){
    getData();
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
        cout << "\nINVALID INPUT\n* Requirements\n  -Future value [0 - INF)\n  -Annual int rate [0 - 1]\n  -Number of years [1 - INF).\n";
    
    return valid;
}

/**
 * @param none
 * @return None
 * @brief Gets future value, annual int rate, and years from user input
*/
void getData(){
    float pValue, fValue, rValue;
    short nValue;
    char ext;
    do{
        cout << "\nEnter the future value: ";
        cin >> fValue;
        cout << "Enter the annual interest rate: ";
        cin >> rValue;
        cout << "Enter the number of years interest will be compound: ";
        cin >> nValue;
    }while(!( inputValidation(fValue, 0, fValue) && inputValidation(rValue, 0, 1) && inputValidation(nValue, 1, nValue)));
    cout << "\nYou need to deposit $ " << calculatePresentValue(fValue, rValue, nValue); 
    cin.ignore();
    cout << "\n\nPress Q to exit. Press anything else to try different values: ";
    ext = getchar();

    if(tolower(ext) != 'q')
        getData();

    cout << "\n\n";
}

/**
 * @param none
 * @return the present value
 * @brief Calculates present value given a future value, annual interest rate, and number of years
*/
float calculatePresentValue(float fArg, float rArg, short nArg){
    return fArg / pow((1 + rArg), nArg);

}