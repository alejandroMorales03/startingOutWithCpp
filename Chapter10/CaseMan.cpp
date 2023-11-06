#include <iostream>

using namespace std;

char* upper(const char*);
char* lower(const char*);
char* reverse(const char*);
void printer(char*);

int main(){
    string line;
    cout << "\nEnter a string: ";
    getline(cin, line);
    cout << "\n";

    const char* c_str = line.c_str();
    char* c_str_results;

    c_str_results = upper(c_str);
    printer(c_str_results);
    delete[] c_str_results;
    
    c_str_results = lower(c_str);
    printer(c_str_results);
    delete[] c_str_results;
    
    c_str_results = reverse(c_str);
    printer(c_str_results);
    delete[] c_str_results;

    c_str_results = nullptr;
    return 0;
}

char* upper(const char* argument){
    char* ptr_c_str = new char[strlen(argument)];
    for(short index = 0; index < strlen(argument); index++)
        ptr_c_str[index] = toupper(argument[index]);

    return ptr_c_str;
}

char* lower(const char* argument){
    char* ptr_c_str = new char[strlen(argument)];
    for(short index = 0; index < strlen(argument); index++)
        ptr_c_str[index] = tolower(argument[index]);

    return ptr_c_str;
}

char* reverse(const char* argument){
    char* ptr_c_str = new char[strlen(argument)];
    for(short index = 0; index < strlen(argument); index++){
        if(isupper(argument[index]))
            ptr_c_str[index] = tolower(argument[index]);
        else if(islower(argument[index]))
            ptr_c_str[index] = toupper(argument[index]);
    }

    return ptr_c_str;
}

void printer(char* line){
    for(short index = 0; index < strlen(line); index++)
        cout << line[index];
    cout << "\n\n";
}

