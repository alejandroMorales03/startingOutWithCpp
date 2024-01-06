#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>
using namespace std;

class Numbers{

    private:
        int number;
        static string keyStrings[21];
        static string thirty;
        static const int MAX = 9999, MIN = 0;

    public:
        Numbers(int number);
        void print();
};

#endif