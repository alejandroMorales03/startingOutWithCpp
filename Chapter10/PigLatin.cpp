#include <iostream>
#include <string>

using namespace std;
string PigLatin(string);

int main(){
    string sent;
    cout << "Enter a sentence: ";
    getline(cin, sent);
    cout << "In Pig Latin: " << PigLatin(sent);
    return 0;
}

string PigLatin(string sentc){
    string result = sentc;
    char swap = result.at(0);

    result.erase(0, 1);
    short index = 0;

    while(index < result.length()){
        if(result.at(index) == ' '){
            if(isalpha(result.at(index - 1))){
                result.insert(index, 1, swap);
                index++;
                result.insert(index, "AY");
                index += 3;
            }
            else{
                index++;
            }
            if(isalpha(result.at(index))){
                swap = result.at(index);
                result.erase(index, 1);
                index++;
            }
        }
        index++;
    }
    result.append(1, swap);
    result += "AY";
    return result;
}