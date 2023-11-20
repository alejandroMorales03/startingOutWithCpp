#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    
    string filename;

    cout << "\nEnter file name: ";
    getline(cin,  filename);

    fstream file(filename, ios::in);

    if(file.fail())
        cout << "\nFILE NOT FOUND...\n\n";
    else{
        cout << "\nFILE OPEN SUCCESSFULLY\n\n";

        string content;
        short lines = 0;
        while(!file.eof()){
            lines++;
            getline(file, content);
                if(lines % 24 == 0){
                    cout << "\nPress any key to continue printing: \n";
                    cin.get();
                }
            if(!file.eof() || (file.eof() && lines == 1))
                cout << setw(2) << (lines + 1) << ":" << content << "\n";
            else
                cout << "\n";
        }
        file.close();
    
    }
    return 0;

}