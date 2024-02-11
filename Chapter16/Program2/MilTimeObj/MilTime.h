#ifndef MILTIME_H
#define MILTIME_H

#include "/Users/alejandromorales/projects/Chapter16/Program2/TimeObject/Time.h"

class MilTime : public Time{
    public:
        MilTime(int userHour = 0, int userSec = 0);

        std::string getTime()const final override;

        virtual ~MilTime();
};


#endif