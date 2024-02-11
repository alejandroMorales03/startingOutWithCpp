#include "/Users/alejandromorales/projects/Chapter16/Program3/MATHASSIST.h"
#include <iostream>

//Code is tested and fully functional
using namespace std;

int main(){
    double doubleArg;
    int intArg;
    char charArg;

    cout << "\nProvide an int, double, and char: ";
    cin >> intArg >> doubleArg >> charArg;

    cout << "\n" << intArg << " Int::Abs = " << absoluteVal(intArg);
    cout << "\n" << doubleArg << " Double::Abs = " << absoluteVal(doubleArg);
    cout << "\n" << charArg << " Char::Abs = " << absoluteVal(charArg) << "\n\n";
    return 0;
}