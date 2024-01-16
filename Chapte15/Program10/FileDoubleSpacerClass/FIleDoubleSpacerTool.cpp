#include "FileDoubleSpacerTool.h"

void FileDoubleSpacerTool::doFilter(std::ifstream& in, std::ofstream& out){
    std::string word;
    while(getline(in, word)){
        out << word << "\n\n";
    }
}