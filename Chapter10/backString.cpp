#include <iostream>
#include <cstring>

using namespace std;
void reverseString(char[]);

int main(){
    char word[10];
    cout << "Enter a string no bigger than 10 chars: ";
    cin.getline(word, 10);
    reverseString(word);
    cout << "\n\n";

    return 0;
}


/**
 * @brief reverses a string
 * 
 * @param word 
 */
void reverseString(char word[]){
    for(short index = strlen(word); index >= 0; index-- )
        cout << word[index];
}
