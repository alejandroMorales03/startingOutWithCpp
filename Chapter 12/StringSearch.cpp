#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//void checkStatus(fstream&);
void readFile(fstream&, vector<string>&);
void writeFile(fstream& , const vector<string>& );
short SearchFile(fstream&, string);
int main(){
    const string FILE = "test1.txt";
    fstream file(FILE, ios::in|ios::out);
    vector<string> container;

    readFile(file, container);
    writeFile(file, container);

    string search_key;
    cout << "\nEnter a value to be searched: ";
    getline(cin, search_key);

    
    cout << SearchFile(file, search_key) << " matches\n\n";

    return 0;

}
/*
void checkStatus(fstream& status){
    cout << "\n\nStatus: ";
    cout << "\nEof: " << status.eof();
    cout << "\nFail: " << status.fail();
    cout << "\nBad: " << status.bad();
    cout << "\nGood: " << status.good();
}*/

void readFile(fstream& file, vector<string>& container){
    string holder;

    while(getline(file, holder)){
        container.push_back(holder);
    }
    file.clear();
}

void writeFile(fstream& sorted_file, const vector<string>& sorted_vector) {    
    sorted_file.seekp(0L, ios::beg);

    for (short index = 0; index < sorted_vector.size(); index++) {
        sorted_file << sorted_vector.at(index) << "\n";
    }
}

short SearchFile(fstream& file, string key){
    file.seekg(0L, ios::beg);
    string line;
    short count = 0;
    while(getline(file, line)){
        if(line.find(key) != std::string::npos){
            cout << line << "\n";
            count++;
        }
    }
    cout << "\n";
    return count;
}



