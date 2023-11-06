#include <iostream>
#include <vector>

using namespace std;
char mostFreq(const char*);

using namespace std;
int main(){
    string input;

    cout << "\nEnter a string: ";
    getline(cin, input);
    cout << "\nMost repeated character is " << mostFreq(input.c_str()) << "\n";

    return 0;
}

char mostFreq(const char* arg_c_str){
    vector<bool>flags(strlen(arg_c_str), false);
    vector<short>freq;
    short highest = 1;
    short highest_index = -1;

    for(short ref = 0; ref < strlen(arg_c_str); ref++){
        if(!flags[ref]){
            freq.push_back(0);
            for(short comp = ref; comp < strlen(arg_c_str); comp++){
                if(!flags[comp]){
                    if(arg_c_str[comp] == arg_c_str[ref]){
                        flags[comp] = true;
                        freq[freq.size() - 1]++;
                    }       
                }
            }
            if(freq[freq.size() - 1] > highest){
                highest = freq[freq.size() - 1];
                highest_index = ref;
            }
        }
    }

    for(short index = 0; index < freq.size(); index++)
        cout << freq[index] << " ";
    
    return arg_c_str[highest_index];

}

