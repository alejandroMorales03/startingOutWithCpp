#include <iostream>
#include <iomanip>

using namespace std;

const float CHARGE_HOUR = 25.0, HOUR_110FEET = 8, FEET = 110.0;

bool inputValidation(float, float, float);

float getGallons(float);
float getHours(float);
float getLaborCost(float);

int main(){
    cout << setprecision(2) << fixed;
    short rooms;
    float feet, gallons = 0, hours = 0, priceLabor = 0, costPaint;
    do{
        cout << "\nHow many rooms will you be painting: ";
        cin >> rooms;
    }while(!inputValidation(rooms, 0, rooms));

    if(rooms == 0){
        cout << "\nNo work is required ";
        exit(0);
    }

    for(short index = 0; index < rooms; index++){
        do{
            cout << "\nEnter the number of squared feet in room " << (index + 1) << ": ";
            cin >> feet;
        }while(!inputValidation(feet, 1, feet));

        gallons += getGallons(feet);
        hours += getHours(feet);
        priceLabor += getLaborCost(getHours(feet));
    }

    do{
        cout << "\nWhat's the cost of the paint: ";
        cin >> costPaint;
    }while(!inputValidation(costPaint, 10, costPaint));

    cout << "\nGallons:                   " << setw(6) << gallons;
    cout << "\nLabor Hours:               " << setw(6) << hours;
    cout << "\nCost of Paint:             " << setw(6) << costPaint * gallons;
    cout << "\nLabor Charges:           $ " << setw(6) << priceLabor;
    cout << "\nTotal Cost of Paint Job: $ " << setw(6) << priceLabor + (costPaint * gallons) << "\n\n";

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
        cout << "\nINVALID INPUT\n";
    return valid;
}

/**
 * @brief Gets the gallon required
 * @param feet
 * @return Returns the number of gallons required to paint the room
*/

float getGallons(float feet){
    return feet / FEET;
}

/**
 * @brief Gets the hours of labor required
 * @param feet
 * @return Returns the number of hours of labor required
*/

float getHours(float feet){
    return feet / 110 * HOUR_110FEET;
}

/**
 * @brief Gets the cost of the labor
 * @param feet
 * @return Returns the amount corresponding to the labor
*/

float getLaborCost(float hour){
    return hour * CHARGE_HOUR;
}

