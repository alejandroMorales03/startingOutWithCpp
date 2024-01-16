#include "EncryptionTool.h"
#include "iostream"

EncryptionTool::EncryptionTool(int key) : FileFilter(){
    setKey(key);
}

void EncryptionTool::doFilter(std::ifstream &in, std::ofstream &out){
    std::string word;
    while(getline(in, word)){
        for(short index  = 0; index < word.length(); index++){
            word.at(index) = word.at(index) + enckey;
        }
        out << word;
    }
}

void EncryptionTool::setKey(int key){
    enckey = key;
}