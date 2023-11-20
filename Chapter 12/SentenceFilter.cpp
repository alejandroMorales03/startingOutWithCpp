#include <iostream>
#include <fstream>

using namespace std;

int main(){ 
    const string READ_FILE = "filter.txt";
    const string WRITE_FILE = "filtered.txt";

    ifstream readFile(READ_FILE);

    if(readFile.fail()){
        cout << "\nFILE NOT FOUND! " << READ_FILE << "\n";
        return 1;
    }

    ofstream writeFile(WRITE_FILE);
    string line;
    while(getline(readFile, line, '.')){
        if(isalpha(line.at(0)))
            line.at(0) = toupper(line.at(0));
        else if(line.at(0) == ' ' && isalpha(line.at(1)))
            line.at(1) = toupper(line.at(1));

        writeFile << line + '.';
    }

    readFile.close();
    writeFile.close();

    return 0;
}