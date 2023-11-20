#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(){
    fstream uncounted("avg.txt", ios::in);
    
    if(uncounted.fail()){
        cout << "\nFILE DOES NOT EXIST\n";
        return 1;
    }
    string line;
    short linecount = 0;
    float words = 0;

    while(getline(uncounted, line)){
        linecount++;
        if(isalpha(line.at(0)))
            words++;
        for(short index = 1; index < line.length() - 1; index++){
            if(isspace(line.at(index)) && isalpha(line.at(index + 1)))
                words++;
        }
    }
    if(linecount > 0)
        cout << "\nAverage words per line: " << words/linecount << "\n\n";
    else
        cout << "\nFile is empty\n\n";
    
    return 0;
}