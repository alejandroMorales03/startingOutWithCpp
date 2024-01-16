#ifndef MILTIME_H
#define MILTIME_H

#include "/Users/alejandromorales/projects/Chapte15/Program4/TimeClass/Time.h"

class MilTime : protected Time{
    private: 
        int milhour;
        int milseconds;

    public:
        MilTime(int militaryhours = 0, int militarseconds = 0);

        std::string getMilHour() const;
        std::string getStdHour();

        virtual ~MilTime(){};
};

#endif