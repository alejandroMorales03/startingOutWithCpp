#include <iostream>
#include <cstring>

using namespace std;
void capitalizer(char*);

int main(){
    cout << "Enter a string no more than 50 characters long: ";
    char line[51];
    cin.getline(line, 51);
    capitalizer(line);

    short index = 0;
    while(*(line + index )!= '\0'){
        cout << *(line + index);
        index++;
    }

    cout << "\n\n";
    return 0;
}

void capitalizer(char* line){
    line[0] = toupper(line[0]);
    while(*line != '\0'){
        if(*line == '.'){
            while(!isalpha(*line) && *line != '\0')
                line++;

            if(*line != '\0')
                *line = toupper(*line);
        }
        line++;
            
    }

}