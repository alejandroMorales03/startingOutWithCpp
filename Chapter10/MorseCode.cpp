#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string morseCode(string);
int main(){
    string line;
    cout << "Enter a string to be translated to morse code: ";
    getline(cin, line);
    cout << morseCode(line) << "\n\n";
    return 0;
}

string morseCode(string input){
    short search_key[] = {32, 44, 46, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 63, 65, 66, 67, 68, 69, 70, 71, 
                          72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

    string code[] = {" ", "--..--", ".-.-.-", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
                     "..--..", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                     ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    string morse_code = "";
    bool found;
    short middle, first, last, search_value;
    for(short search_i = 0; search_i < input.length(); search_i++){
        found = false;
        first = 0, last = sizeof(search_key)/sizeof(search_key[0]);

        search_value = static_cast<int>(toupper(input.at(search_i)));

        while(!found && first <= last){
            middle = (first + last) / 2;

            if(search_value == search_key[middle]){
                found = true;
                morse_code += code[middle];
            }
            else if(search_value > search_key[middle]){
                first = middle + 1;
            }
            else{
                last = middle - 1;
            }
        }
    }
    return morse_code;
    

}