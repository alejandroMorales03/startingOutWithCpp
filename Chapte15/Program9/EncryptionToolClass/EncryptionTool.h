#ifndef ENCRYPTIONLTOOL_H
#define ENCRYPTIONLTOOL_H

#include "/Users/alejandromorales/projects/Chapte15/Program9/FileFilterClass/FileFilter.h"

class EncryptionTool : public FileFilter{
    private:
        int enckey;
    public:
        EncryptionTool(int key = 0);
        
        virtual void doFilter(std::ifstream &in, std::ofstream &out);
        void setKey(int key = 0);

        ~EncryptionTool(){}

};

#endif