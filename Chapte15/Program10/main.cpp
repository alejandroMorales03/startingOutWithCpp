#include "/Users/alejandromorales/projects/Chapte15/Program10/FileDoubleSpacerClass/FileDoubleSpacerTool.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    string word;
    ofstream writeFile("unspaced.txt");
    ifstream readFile;
    if(writeFile.fail())
        throw std::runtime_error("UNSPANCE FILE OPENING ERROR");

    cout << "\nPress ~ when your done entering the contents of the initial file:";
    getline(cin, word);
    int index = 0;

    while(word != "~"){
        cout << index;

        writeFile << word << "\n";
        getline(cin, word);
    }

    writeFile.clear();
    writeFile.close();

    readFile.open("unspaced.txt");
    writeFile.open("spaced.txt");

    if(writeFile.fail() || readFile.fail())
        throw std::runtime_error("ERROR OPENING SPACE/UNSPACE FILE FOR MODIFYING");

    FileDoubleSpacerTool doubleSpace;
    doubleSpace.doFilter(readFile, writeFile);
    readFile.clear();
    readFile.close();
    writeFile.clear();
    writeFile.close();
    return 0;
}