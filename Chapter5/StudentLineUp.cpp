#include <iostream>

using namespace std;

int main(){

    string input, last, first;
    short students;
    do{
        cout << "\nEnter the number of students in the class: ";
        cin >> students;
        cin.ignore();
        if(students < 1 || students > 25)
            cout << "\nINVALID INPUT! \n* Only works with classes with 1 to 25 students\n";
    }while(students < 1 || students > 25);

    cout << "\nEnter student's name: \n";
    
    for (int i = 0; i < students; ++i) {
        cout << i + 1 << ". ";
        getline(cin, input);

        if (i == 0) {
            first = last = input;
        } else {
            if (input < first) {
                first = input;
            }
            if (input > last) {
                last = input;
            }
        }
    }

    
    cout << "\nFirst: " << first;
    cout << "\nLast: " << last << "\n\n";
    return 0;
}