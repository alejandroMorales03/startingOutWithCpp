#include "CharModTool.h"

char CharModTool::transform(char ch){
    return toupper(ch);
} 

void CharModTool::doFilter(std::ifstream &in, std::ofstream &out){
    char input;
    while(in.get(input)){
        out.put(transform(input));
    }
}