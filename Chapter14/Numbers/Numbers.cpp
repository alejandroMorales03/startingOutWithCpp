#include "Numbers.h"
#include <iostream>


using namespace std;

string Numbers::keyStrings[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                                "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
string Numbers::thirty = "thir";




Numbers::Numbers(int number){
    this->number = number < 0? 9999 : number > 9999 ? 0 : number;
}

void Numbers::print(){
    double copyOfNumber = number;
    int print;
    int modulus = 1; 
    string modulusString;

    cout << "\n";
    do{

        if(copyOfNumber >= 1000){
            modulus = 1000;
            modulusString = " thousand ";
        }
            
        else if(copyOfNumber >= 100){
            modulus = 100;
            modulusString = " hundred ";
        }

        else if(copyOfNumber > 20){
            modulus = 10;
            modulusString = "ty ";
        }
        else{
            modulus = 1;
        }
    
        print = copyOfNumber / modulus;
        cout << (copyOfNumber < 40 && copyOfNumber >= 30? thirty: keyStrings[print]);

        copyOfNumber -= print * modulus;
        

        
        if(copyOfNumber > 0)
            cout << modulusString;
        

    }while(copyOfNumber > 0);

    
}