#include <iostream>
using namespace std;

bool inputValidation(float, float, float);
float calculateRetail(float, float);

/**
 * @param None
 * @return Returns 0 to signal successful program exit
 * Description: Includes main functionalities (i.e retireving data from user and calling assisting functions)
*/

int main(){

    float wholeSalePrice, markUpPercentage, retailPrice; 
    do{
        cout << "\nEnter whole sale price for item: $ ";
        cin >> wholeSalePrice;
        cout << "\nEnter markup percentage (%): ";
        cin >> markUpPercentage;
        markUpPercentage /= 100;
    }while(!(inputValidation(wholeSalePrice, 0, wholeSalePrice) && inputValidation(markUpPercentage, 0, markUpPercentage)));
    cout << "\nRetail Price: $ " << calculateRetail(wholeSalePrice, markUpPercentage) << "\n\n";
    return 0;
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
        cout << "\nINVALID INPUT\n* All data entered must be positive.\n";
    
    return valid;
}

/**
 * @param float,float
 * @return The retail price given a wholesale price and markup rate
 * Description: The method uses the wholeprice and markupRate to calculate the retail price that would generate 
 * profit equivalent to the wholesale price plus the markup percentage. 
*/
float calculateRetail(float w_price, float mup_rate){
    return w_price + (w_price * mup_rate);
}
