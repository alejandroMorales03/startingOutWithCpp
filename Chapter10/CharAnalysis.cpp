#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void filePopulator(ofstream&);
short* charAnalys(ifstream&);

int main(){
    ofstream data_collection("characters.txt");
    filePopulator(data_collection);

    if(!data_collection.fail()){
        filePopulator(data_collection);
        data_collection.close();

        ifstream data_analysis("characters.txt");
        short* analysis_results;
        analysis_results = charAnalys(data_analysis);

        cout << "Uppercase characters: " << *analysis_results << "\n";
        cout << "Lowercase characters: " << analysis_results[1] << "\n";
        cout << "Digits characters: " << analysis_results[2] << "\n";

        delete[] analysis_results;
        analysis_results = nullptr;
    }
    else
        cout << "\nFILE COULD NOT BE POPULATED\n\n";

    return 0;
}

void filePopulator(ofstream& file){
    short size = 10;
    srand(time(0));

    for(short count = 1; count <= size; count++){
        file << static_cast<char>(rand() % (126 - 65 + 1) + 65);
    } 
}

short* charAnalys(ifstream& analysis){
    short* analysis_results = new short[3];
    char test;

    for(short i = 0; i < 3; i++)
        analysis_results[i] = 0;

    while(analysis.get(test)){
        if(isdigit(test))
            analysis_results[2]++;
        else if(isupper(test))
            analysis_results[0]++;
        else if(islower(test))
            analysis_results[1]++;
    }   
    return analysis_results;           
}

