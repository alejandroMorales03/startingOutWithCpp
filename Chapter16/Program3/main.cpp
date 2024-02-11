#include "MATHASSIST.h"
#include <iostream>

using namespace std;

//Code is tested and fully operational

int main(){
    
    int intOne, intTwo;
    cout << "\nTest 2 integers: ";
    cin >> intOne >> intTwo;
    cout << "\nMAX: " << highest(intOne, intTwo); 
    cout << "\nMIN: " << lowest(intOne, intTwo); 
    cout << "\n";

    double doubleOne, doubleTwo;
    cout << "\nTest 2 doubles: ";
    cin >> doubleOne >> doubleTwo;
    cout << "\nMAX: " << highest(doubleOne, doubleTwo); 
    cout << "\nMIN: " << lowest(doubleOne, doubleTwo); 
    cout << "\n";

    char charOne, charTwo;
    cout << "\nTest 2 chars: ";
    cin >> charOne >> charTwo;
    cout << "\nMAX: " << highest(charOne, charTwo); 
    cout << "\nMIN: " << lowest(charOne, charTwo); 
    cout << "\n";

    std::string strOne, strTwo;
    cout << "\nTest 2 String Objects: ";
    std::cin.ignore();
    getline(cin, strOne);
    getline(cin, strTwo);
    cout << "\nMAX: " << highest(strOne, strTwo); 
    cout << "\nMIN: " << lowest(strOne, strTwo); 
    cout << "\n";
    
    
    return 0;
}