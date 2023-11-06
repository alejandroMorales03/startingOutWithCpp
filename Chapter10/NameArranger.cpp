#include <iostream>
#include <vector>

using namespace std;

string Formatted(string);
int main(){
    string name;

    cout << "Enter your name in the format (First Middle Last): ";
    getline(cin, name);
    cout << Formatted(name);

    cout << "\n\n";
    return 0;

}

string Formatted(string input){
    bool found = false;
    short delimeter = -1;
    string formatted;
    for(short index = input.length() - 1; index >= 0 && !found; index--){
        if(input.at(index) == ' '){
            found = true;
            delimeter = index + 1;
        }
    }
    if(delimeter != -1){
        formatted = input.substr(delimeter, input.length() - delimeter) + ", ";
        formatted += input.substr(0, delimeter - 1);
    }
    else
        formatted = "Unproperly Formatter Input";
    return formatted;


}