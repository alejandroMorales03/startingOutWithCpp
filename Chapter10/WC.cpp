#include <iostream>
#include <string>
using namespace std;

int VowelCounter(const char*);
int ConstCounter(const char*);
int letterCounter(const char*, short);
int main(){
    short exit_program;
    do{
        string line;
        cout << "Enter a string: ";
        getline(cin, line);
        const char* c_str = line.c_str();

        cout << "\nVowels: " << VowelCounter(c_str);
        cout << "\nConstants: " << ConstCounter(c_str);
        cout << "\nVowels + Constants: " << letterCounter(c_str, line.length());
        do{
            cout << "\n\n1. Enter another String\n2. Quit the Program\n\nSelection: ";
            cin >> exit_program;
            if(exit_program > 2 || exit_program < 1)
                cout << "\nINVALID INPUT. CHOOSE 1 OR 2.";
        }while(exit_program > 2 || exit_program < 1);
        cin.ignore();
        exit_program--;
    }while(!exit_program);
    cout << "\n";
    return 0;
}

int VowelCounter(const char* line){
    int total = 0;
    while(*line != '\0'){
        if(toupper(*line) == 'A' || toupper(*line) == 'E' || toupper(*line) == 'I' || toupper(*line) == 'O' || toupper(*line) == 'U')
            total++;
        line++;
    }
    return total;
}

int ConstCounter(const char* line){
    int total = 0;
    while(*line != '\0'){
        if(isalpha(*line)){
            if(!(toupper(*line) == 'A' || toupper(*line) == 'E' || toupper(*line) == 'I' || toupper(*line) == 'O' || toupper(*line) == 'U'))
                total++;
        }  
        line++; 
    }
    return total;   
}

int letterCounter(const char* line, short length){
    int total = 0;
    while(*line != '\0'){
        if(!isalpha(*line))
            total++;

        line++;
    }
    return length - total;

}