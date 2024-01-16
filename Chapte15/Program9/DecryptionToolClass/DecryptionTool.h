#ifndef DECRYPTIONTOOL_H
#define DECRYPTIONTOOL_H

#include "/Users/alejandromorales/projects/Chapte15/Program9/FileFilterClass/FileFilter.h"

class DecryptionTool : public FileFilter{
    private:
        int deckey;
    public:
        DecryptionTool(int key = 0);
        void setDecKey(int key = 0);
        virtual void doFilter(std::ifstream &in, std::ofstream &out);

        virtual ~DecryptionTool(){}


};

#endif