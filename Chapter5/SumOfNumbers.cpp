#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    short input_number;
    do{
        cout << "\nEnter a positive number: ";
        cin >> input_number;
        if(input_number < 0)
        cout << "\nINVALID INPUT!\n";
    }while(input_number < 0);
    short sum = 0;

    for(int counter = 0; counter <= input_number; counter++){
        sum+= counter;
    }
    
    cout << "\nSum: " << sum << "\n\n";
    return 0;
}