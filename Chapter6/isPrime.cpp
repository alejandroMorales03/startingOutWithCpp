#include <iostream>
using namespace std;

bool isPrime(short);
bool inputValidation(float, float, float);

int main(){
    
    short value;
    do{
        cout << "\nEnter a number: ";
        cin >> value;
    }while(!inputValidation(value, 0, value));
    if(isPrime(value))
        cout << "\n" << value << " is prime\n\n";
    else    
        cout << "\n" << value << " is not prime\n\n";

    cout << "Printing Prime Numbers Smaller than 100...\n\n";
    for(short index = 1; index < 100; index++){
        if(isPrime(index))
            cout << index << " ";
    }
    cout << "\n\n";
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
        cout << "\nINVALID INPUT\n* All prime numbers are positive\n";
    
    return valid;
}

bool isPrime(short value){
    short factor = 0;
    for(short i = 1; i <= value; i++){
        if(value % i == 0)
            factor++;
    }
    if(factor > 2)
        return false;
    else    
        return true;

}
