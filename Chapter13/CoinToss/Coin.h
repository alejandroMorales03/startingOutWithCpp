#ifndef COIN_H
#define COIN_H

#include <string>

using namespace std;

class Coin{
    private:
        string sideUp;

    public:
        Coin();
        void toss();
        string getSideUp();
};

#endif