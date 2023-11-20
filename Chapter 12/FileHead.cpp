#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string filename;
    cout << "\nEnter file name: ";
    getline(cin, filename);
    
    fstream readFile(filename, ios::in);

    if(readFile.fail())
        cout << "\nFILE NOT FOUND...\n";
    else{
        cout << "\nFILE OPENED SUCCESSFULLY...\n\n";
    
        short count = 0;
        string content;
        while(getline(readFile, content) && count < 10){
            cout << content << "\n";
            count++;
        }

        if(count < 10 && readFile.eof())
            cout << "\nEntire file has been printed";
        cout << "\n\n";

        readFile.close();
        

    }
    return 0;
}