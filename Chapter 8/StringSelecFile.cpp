#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
void writeToFile(ofstream&);
void readFromFile(ifstream& , vector<string>&);
void selectionSort(vector<string>&);
int main(){

    vector<string>words(0);
    ofstream writer("/Users/alejandromorales/Desktop/Projects/Chapter 8/text.txt");
     if(!writer.fail()){
        writeToFile(writer);
        writer.close();
    }
    else{
        cout << "\nERROR: FILE COULD NOT BE SAVED..\n";
    }

    
    ifstream reader("/Users/alejandromorales/Desktop/Projects/Chapter 8/text.txt");
    if(!reader.fail()){
        readFromFile(reader, words);
        reader.close();
    }
    else{
        cout << "\nERROR: FILE COULD NOT BE READ..\n";
    }
    
    selectionSort(words);
    for(short index = 0; index < words.size(); index++){
        cout << words[index] << "\n";
    }
    cout << "\n";
    return 0;
}

void writeToFile(ofstream& fileWrite){
    srand(time(0));
    string word;
    short words = (rand() % (100 - 1 + 1) + 1);
    for(short index = 0; index < words; index++){
        word = "";
        for(short length = 0; length < (rand() % (15 - 2 +1) +2); length++){
            word += static_cast<char>(rand() % (90 - 65 + 1) + 65);
        }
        fileWrite << word;
        if(index != words - 1)
            fileWrite << "\n";

    }

}
void readFromFile(ifstream& fileRead , vector<string>&words){
    string holder;
    while(getline(fileRead, holder)){
        words.push_back(holder);

    }
}

void selectionSort(vector<string>& words){
    string MinValue;
    short minIndex;

    for(short startScan = 0; startScan < words.size() - 1; startScan++){
        minIndex = startScan;
        MinValue = words[startScan];

        for(short index = startScan + 1; index < words.size(); index++){
            if(words[index] < MinValue){
                MinValue = words[index];
                minIndex = index;
            }

        }

        words[minIndex] = words[startScan];
        words[startScan] = MinValue;
    }
}