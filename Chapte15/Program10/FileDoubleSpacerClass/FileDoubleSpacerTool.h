#ifndef FILEDOUBLESPACER_H
#define FILEDOUBLESPACER_H

#include "/Users/alejandromorales/projects/Chapte15/Program9/FileFilterClass/FileFilter.h"
class FileDoubleSpacerTool : public FileFilter{
    public:
        FileDoubleSpacerTool() : FileFilter(){};
        virtual void doFilter(std::ifstream& in, std::ofstream& out);
};

#endif