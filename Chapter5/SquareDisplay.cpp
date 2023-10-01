#include <iostream>

using namespace std;

int main(){
    short length;;

    do{
        cout << "\nEnter length of sides of the square: ";
        cin >> length;
        if(length < 1)
            cout << "\nINVALID INPUT!\n* Length must be at least 1\n";
    }while(length < 1);

    for(short row = 0; row < length; row++){
        cout << "\n";
        for(short col = 0; col < length; col++){
            cout << "X ";
        }
    }
    cout << "\n\n";
    return 0;
}