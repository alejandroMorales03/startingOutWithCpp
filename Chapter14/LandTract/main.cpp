#include "LandTract.h"
#include <iostream>

using namespace std;

int main(){
    FeetInches length, width;

    cout << "\nFor the first tract: ";
    cout << "\nLength: ";
    cin >> length;
    cout << "\nWidth: ";
    cin >> width;

    LandTract trackOne(length, width);

    cout << "\nFor the second tract: ";
    cout << "\n\nLength: ";
    cin >> length;
    cout << "\nWidth: ";
    cin >> width;

    LandTract trackTwo(length, width);

    cout << trackOne << "\nArea: " << trackOne.getArea();
    cout << "\n" << trackTwo << "\nArea: " << trackTwo.getArea();

    if(trackOne == trackTwo)
        cout << "\nSUCCESS\n\n";
    else
        cout << "\nFAILURE\n\n";

    return 0;


}