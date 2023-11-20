#include <iostream>
#include <fstream>

using namespace std;

void encrypt(fstream&, fstream&);
void decrypt(fstream&, fstream&);
int main(){
    fstream unenc("unenc.txt", ios::in);
    fstream enc("enc.txt", ios::out);

    if(unenc.fail() || enc.fail()){
        cout << "\nFILE OPENING FAIL...\n";
        return 1;
    }

    encrypt(unenc, enc);
    unenc.close();
    enc.close();

    return 0;
}

void encrypt(fstream& unenc, fstream& enc){
    string lineholder;
    while(getline(unenc, lineholder, '.')){
        lineholder += '.';
        for(short index = 0; index < lineholder.length(); index++){
            enc << static_cast<int>(lineholder.at(index)) + 473 << ' ';
        }
        enc << "\n";
    }
}