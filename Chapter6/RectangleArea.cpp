#include <iostream>
using namespace std;

bool inputValidation(float, float, float);
float getLength();
float getWidth();
float getArea();
void displayData();


/**
 * @param None
 * @return Returns 0 to signal successful program exit
 * Description: Performs only main actions such as displaying the final result
*/

int main(){
    displayData();
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
    if(checkValue >= minValue && checkValue >= maxValue)
        valid = true;
    else
        cout << "\nINVALID INPUT\n* All data entered must be positive.\n";
    
    return valid;
}

/**
 * @param none
 * @return The length of the rectangle
 * Description: Asks the user for the length of the rectangle and performs data validation.
*/
float getLength(){
    float length;
    do{
        cout << "\nEnter length of rectangle: ";
        cin >> length;
    }while(!inputValidation(length, 0, length));
    return length;
}

/**
 * @param none
 * @return The width of the rectangle
 * Description: Asks the user for the width of the rectangle and performs data validation.
*/
float getWidth(){
    float width;
    do{
        cout << "Enter with of rectangle: ";
        cin >> width;
    }while(!inputValidation(width, 0, width));
    cout << "\nThe area of the rectangle is ";
    return width;
}

/**
 * @param none
 * @return The are of the rectangle
 * Description: Performs calls to getWith() and getLength() and uses return values to calculate area;
*/
float getArea(){
    return getLength() * getWidth();
}


/**
 * @param none
 * @return Nothing
 * Description: Displays a message with the area of the rectangle
*/
void displayData(){
    cout << "\nCalculating Area of Rectange\n" << getArea() << "\n\n";
}