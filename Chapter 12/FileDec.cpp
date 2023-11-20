#include <iostream>
#include <fstream>

using namespace std;

void decrypt(fstream&, fstream&);
int main(){
    fstream encr("enc.txt", ios::in);
    fstream decr("decr.txt", ios::out);

    if(encr.fail() || decr.fail()){
        cout << "\nFILE OPEN FAIL\n";
    }
    decrypt(encr, decr);
    decr.close();
    encr.close();
    

    return 0;
}

void decrypt(fstream& enc, fstream& dec){
    int holder;
    while(enc >> holder){
        
        dec << static_cast<char>(holder - 473);
        
        if(static_cast<char>(holder - 473) == '.'){
            dec << "\n";
            enc >> holder;
            if(holder - 473 != ' ')
                dec << static_cast<char>(holder - 473);
        }
    }
}
