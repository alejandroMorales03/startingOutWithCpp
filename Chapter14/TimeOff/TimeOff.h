#ifndef TIMEOFF_H
#define TIMEOFF_H

#include "/Users/alejandromorales/projects/Chapter14/NumDays/Numdays.h"
#include "iostream"

using namespace std;

class  TimeOff{
    private:
        Numdays maxSick;
        Numdays takenSick;
        Numdays maxVac;
        Numdays takenVac;
        Numdays maxUnpaid;
        Numdays takenUnpaid;

        string name;
        string empID;

        enum{VACATION_LEAVE = 12, SICK_LEAVE = 8, VACATION_MAX_HOURS = 240};
        Numdays checKVacMaxThreshold(float months);

    public:
        TimeOff(string newEmpName = "New Employee", string newEmpID = "####XX");

        int getMaxSick()const;
        int getSickTaken()const;
        int getMaxVac()const;
        int getVacTaken()const;
        int getMaxUnp()const;
        int getUnpTaken()const;

        void setMaxSick(float hours);
        void setSickTaken(float hours);
        void setMaxVac(float hours);
        void setVacTaken(float hours);
        void setMaxUnp(float hours);
        void setUnpTaken(float hours);

        void updateTimeOff(float months);
        void scheduleVacation(float months);

};


#endif