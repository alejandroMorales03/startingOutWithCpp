#include <iostream>

using namespace std;

string camelSeparator(string&);
int main(){

    string camel;
    
    cout << "\nEnter a string of words without spaces between them and ";
    cout << "only capitalize the first letter of each word: ";
    getline(cin, camel);
    cout << camelSeparator(camel);
    cout << "\n\n";

    return 0;
}

string camelSeparator(string &camel){
    short index = 0;
    while(index < camel.length()){
        if(isupper(camel.at(index)) && index != 0){
            camel.insert(index, 1, ' ');
            index++;
        }
        index++;
    }
    return camel;
}
