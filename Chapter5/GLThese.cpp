#include <iostream>
using namespace std;

int main(){

    float input, largest, smallest;
    cout << "\nEnter a series of numbers separated by spaces or new lines (Press -99 when done): ";
    cin >> input;

    largest = smallest = input;

    while(input != -99){
        largest = largest > input? largest : input;
        smallest = smallest < input? smallest : input;
        cin >> input;
    }

    cout << "\nLargest: " << largest;
    cout << "\nSmallest: " << smallest << "\n\n";
    return 0;
}