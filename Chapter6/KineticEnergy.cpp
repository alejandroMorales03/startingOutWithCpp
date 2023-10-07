#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const float HALF = 0.5;
float keCalculator(float, float);
void getData();

int main(){
    getData();
    return 0;
}
/**
 * @param float,float
 * @return The kinetic energy given a weight and a velocity
 * Description: The function calculates the kinetic energy given a weight and a velocity
*/

float keCalculator(float weight , float velocity){
    return HALF * weight * pow(velocity, 2);
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
        cout << "\nINVALID INPUT\n* Weight must be positive.\n";
    return valid;
}

/**
 * @param float,float,float
 * @return Nothing
 * Description: Gets the data for the weight and the veloctiy. Performs input validation on the weight. Calls
 * keCalculator.
 */
void getData(){
    float weight, velocity;
    do{
        cout << "\nEnter weight (kg): ";
        cin >> weight;
    }while(!inputValidation(weight, 0, weight));
    
    cout << "Enter velocity in m/s: ";
    cin >> velocity;

    cout << "\nThe kinetic energy is " << keCalculator(weight, velocity) << " kg m^2 / s^2\n\n";
}