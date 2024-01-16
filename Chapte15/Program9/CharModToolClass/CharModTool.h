#ifndef CHARMODTOOL_H
#define CHARMODTOOL_H

#include "/Users/alejandromorales/projects/Chapte15/Program9/FileFilterClass/FileFilter.h"

class CharModTool : public FileFilter{
    private:
        char transform(char ch);
    public:
        CharModTool():FileFilter(){};
        virtual void doFilter(std::ifstream &in, std::ofstream &out);
        virtual ~CharModTool(){};
};

#endif