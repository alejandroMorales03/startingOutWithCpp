#include "test.h"
#include <iostream>

using namespace std;


 


int main(){
    int num_tests;
    int index;

    do{
        cout << "\nHow many tests were taken: ";
        cin >> num_tests;
        if(num_tests < 1)
            cout << "\nThe number of tests must be 1 or more\n";
    }while(num_tests < 1);

    test myTest(num_tests);

    cout << "\nWhat test score would you like to print? (1, 2, 3...): ";
    cin >> index;

    index--;

    if(myTest.getTest(index).condition)
        cout << "\nTest #" << index + 1 << " was " << myTest.getTest(index).score;
    else
        cout << "\nThat test does not exist. Returning first test " << myTest.getTest(index).score << "\n";

    float score;
    cout << "\nWhat index would you like to change: ";
    cin >> index;
    cout << "\nWhats the new score: ";
    cin >> score;
    
    index--;
    myTest.setTest(index, score);
    if(myTest.getTest(index).condition)
        cout << "\nTest #" << index + 1 << " was " << myTest.getTest(index).score;
    else
        cout << "\nThat test does not exist. Returning first test " << myTest.getTest(index).score << "\n";

    cout << "\nAverage: " << myTest.getAverage() << "\n\n";



    return 0;
}