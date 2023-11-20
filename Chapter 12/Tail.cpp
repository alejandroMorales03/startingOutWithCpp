#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateFile(fstream&);
void getTail(fstream&);

int main(){
    fstream file;
    generateFile(file);
    getTail(file);

    file.close();
    return 0;
}

void generateFile(fstream& file){
    file.open("tail.txt", ios::out);
    srand(time(0));

    for(short line = 0; line < (rand() % (100 - 1 + 1) + 1); line++){
        for(short charact = 0; charact < (rand() % (100 - 1 + 1) + 1); charact++)
            file << static_cast<char>(rand() % (126 - 32 + 1) + 32);
        file << "\n";
    }
    file.close();
}

void getTail(fstream& file){
    file.open("tail.txt", ios::in|ios::app);
    if(file.fail()){
        cout << "\n\nFILE NOT FOUND\n\n";
        exit(1);
    }
    file.clear();

    file.seekg(-1L, ios::end);
    
    short count = 0;
    while(file.tellg() > 0 && count <= 10){
        if(file.get() == '\n')
            count++;
        file.seekg(-2L, ios::cur);
    }

    if(file.tellg() != 0)
            file.seekg(2L, ios::cur);
    
    file.clear();
    string line;
    cout << "\n";
    while(getline(file, line)){
        cout << line << "\n";
    }

    if(count < 10)
        cout << "\nThe entire file has been printed\n";
    cout << "\n";

    file.close();
}