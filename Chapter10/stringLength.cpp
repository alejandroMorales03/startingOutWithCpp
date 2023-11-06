#include <iostream>
#include <cstring> 

using namespace std;

int charCounter(char*);

int main() {
    char word[50];
    cout << "Enter a string (No more than 49 characters): ";
    cin.getline(word, 50);

    cout << "There are " << charCounter(word) << " characters in ";

    short index = 0;
    while (*(word + index) != '\0') {
        cout << *(word + index);
        index++;
    }
    cout << "\n";

    return 0;
}

/**
 * @brief counts characters in a string using the strlen cstring function
 * 
 * @param word 
 * @return int 
 */
int charCounter(char* word) {
    return strlen(word);
}
