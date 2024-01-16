#include "DecryptionTool.h"
#include "iostream"

DecryptionTool::DecryptionTool(int key) : FileFilter(){
    setDecKey(key);
}

void DecryptionTool::doFilter(std::ifstream &in, std::ofstream &out){
    std::string word;
    while(getline(in, word)){
        for(short index  = 0; index < word.length(); index++){
            word.at(index) = word.at(index) - deckey;
        }
        out << word;
    }
}

void DecryptionTool::setDecKey(int key){
    deckey = key;
}