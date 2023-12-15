#ifndef DIE_H
#define DIE_H

#include <string>
using namespace std;

class Die{
    private:
        short sideUp;
        short points;

        void updatePoints();

    public:
        Die();
        short Roll();
        string checkCaught();
        string getMessage() const;
        short getPoints()const;


};

#endif