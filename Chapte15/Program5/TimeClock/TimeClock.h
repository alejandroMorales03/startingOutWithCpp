#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include "/Users/alejandromorales/projects/Chapte15/Program4/MilTimeClass/MilTime.h"

class TimeClock : protected MilTime{
    private:
        MilTime startingTime;
        MilTime endingTime;

        int elapsed;

    public:
        TimeClock(int start = 0, int end = 0);
        std::string getElapsed();

};

#endif