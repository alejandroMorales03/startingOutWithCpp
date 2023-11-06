#include <iostream>
using namespace std;

void replaceStr(string&, string&, string&);
int main(){
    string pool, key, replacement;
    cout << "Enter a string to be the pool: ";
    getline(cin, pool);
    cout << "Enter a string to be the searched for: ";
    getline(cin, key);
    cout << "Enter a string to be the used as replacement: ";
    getline(cin, replacement);

    replaceStr(pool, key, replacement);
    cout << "\n" << pool << "\n\n";

    return 0;
}

void replaceStr(string &p_str, string &k_str, string &r_str) {
    int index = 0;
    while ((index = p_str.find(k_str, index)) != string::npos) {
        p_str.replace(index, k_str.length(), r_str);
        index += r_str.length() - k_str.length();
    }
}

