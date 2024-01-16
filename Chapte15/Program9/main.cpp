#include <iostream>
#include <fstream>
#include "/Users/alejandromorales/projects/Chapte15/Program9/EncryptionToolClass/EncryptionTool.h"
#include "/Users/alejandromorales/projects/Chapte15/Program9/DecryptionToolClass/DecryptionTool.h"
#include "/Users/alejandromorales/projects/Chapte15/Program9/CharModToolClass/CharModTool.h"


using namespace std;

int main(){

    //Focusing in the encrypting tool
    ofstream initialFile("EncReadFile.txt");

    if(initialFile.fail())
        std::runtime_error("ENC READ FILE COULDNT BE OPEN FOR INITIAL WRITING");

    string message;
    int key;

    cout << "\nWhat would you like to encrypt and what key would you like to use: ";
    cout << "\nMessage: ";
    getline(cin, message);
    cout << "\nKey: ";
    cin >> key;

    EncryptionTool myENC(key);

    //Writing something to it.
    initialFile << message;
    initialFile.close();

    //Opening file for readining unencryped data

    ifstream encReadFile("EncReadFile.txt");
    ofstream encWriteFile("EncWriteFile.txt");

    if(encReadFile.fail() || encWriteFile.fail())
       std::runtime_error("ENCREAD/ENCWRITE FILE COULDNT BE OPEN ENCRYPTION TOOL");

    myENC.doFilter(encReadFile, encWriteFile);

    encReadFile.close();
    encWriteFile.close();

    //Now focusing on decrypting the file

    DecryptionTool myDec(key);
    encReadFile.open("EncWriteFile.txt");
    if(encReadFile.fail())
        throw std::runtime_error("ERROR OPENING ENCWRITEFILE FOR DECRYPTING TOOL");

    ofstream decriptedFile("DecryptedFile.txt");
    if(decriptedFile.fail())
        throw std::runtime_error("ERROR OPENING DECRYPTED FILE FOR DECRYPTING TOOL");

    myDec.doFilter(encReadFile, decriptedFile);

    encReadFile.clear();
    decriptedFile.clear();
    encReadFile.close();
    decriptedFile.close();

    decriptedFile.open("DecryptedFile.txt");
    encReadFile.open("EncReadFile.txt");

    if(decriptedFile.fail() || encReadFile.fail())
        throw std::runtime_error("ERROR OPENING DECRYPTED/ENCREAD FILE FOR CCHAR TOOL");

    CharModTool myChar;
    myChar.doFilter(encReadFile, decriptedFile);



    





    return 0;
}