#include <iostream>
#include <fstream>

using namespace std;

void writeFile(string, string*, short);
void readFile(string, string*, short);

int main(){
    string file_name;
    string content[] = {"achieve", "fail", "power", "destruction", "random", "fixed"};
    cout << "\nEnter a file name: ";
    getline(cin, file_name);

    writeFile(file_name, content, sizeof(content));
    string* new_content = new string[sizeof(content)/sizeof(content[0])];
    readFile(file_name, new_content, sizeof(content));

    for(short index = 0; index < sizeof(content)/sizeof(content[0]); index++){
        cout << new_content[index] << ",";
    }
    cout << "\n\n";
    delete[] new_content;
    new_content = nullptr;

    return 0;
}

void writeFile(string fileName, string* ptr, short size){
    fstream writeFile(fileName, ios::out|ios::binary);
    writeFile.write(reinterpret_cast<char*>(ptr), size);
}
void readFile(string fileName, string* ptr, short size){
    fstream readFile(fileName, ios::in|ios::binary);
    readFile.read(reinterpret_cast<char*>(ptr), size);
}