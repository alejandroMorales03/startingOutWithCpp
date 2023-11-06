#include <iostream>
#include <cctype>

using namespace std;

short c_stringWordCounter(char*);
float averageCharInWord(char*);

int main(){
    char line[101];
    cout << "\nEnter a s tring that is no more than 100 characters long: ";
    cin.getline(line, 101);
    cout << c_stringWordCounter(line) << " words";
    cout << "\n" << averageCharInWord(line) << " chars per word\n\n";
    
    return 0;
}

short c_stringWordCounter(char* line) {
    float words = 0;
    bool check = false;

    while (*line != '\0') {
        if (isalpha(*line)) {
            check = true;
        } else {
            if (check) {
                words++;
                check = false;
            }
        }
        line++;
    }

    if (check) {
        words++;
    }

    return words;
}

float averageCharInWord(char* line){
    float total = 0;
    char* ptr = line;
    while(*ptr != '\0'){
        if(isalpha(*ptr))
            total++;
        ptr++;
    }

    return total / c_stringWordCounter(line);

}