#include "TimeOff.h"
#include <iostream>

using namespace std;

TimeOff::TimeOff(string newEmpName, string newEmpID){
    name = newEmpName;
    empID = newEmpID;
}

int TimeOff::getMaxSick()const{
    return maxSick.getWorkDays();
}
int TimeOff::getSickTaken()const{
    return takenSick.getWorkDays();
}
int TimeOff::getMaxVac()const{
    return maxVac.getWorkDays();
}
int TimeOff::getVacTaken()const{
    return takenVac.getWorkDays();
}
int TimeOff::getMaxUnp()const{
    return maxUnpaid.getWorkDays();
}
int TimeOff::getUnpTaken()const{
    return takenUnpaid.getWorkDays();
}
void TimeOff::setMaxSick(float hours){
    maxSick.setWorkedHours(hours);
}

void TimeOff::setSickTaken(float hours){
    takenSick.setWorkedHours(hours);
}
void TimeOff::setMaxVac(float hours){
    maxVac.setWorkedHours(hours);
}
void TimeOff::setVacTaken(float hours){
    takenVac.setWorkedHours(hours);
}
void TimeOff::setMaxUnp(float hours){
    maxUnpaid.setWorkedHours(hours);
}
void TimeOff::setUnpTaken(float hours){
    takenUnpaid.setWorkedHours(hours);
}

Numdays TimeOff::checKVacMaxThreshold(float months){
    if(months * VACATION_LEAVE > VACATION_MAX_HOURS){
        cout << "\n\nYOU CANNOT LONGER ACCUMULATE VACATION DAYS: \n";
        cout << "\n1. Schedule a Vacation";
        scheduleVacation(months);
    }
    return this->maxVac;
}

void TimeOff::scheduleVacation(float months){
    int days;
    int remaining = months * VACATION_LEAVE - VACATION_MAX_HOURS;
    this->maxVac = VACATION_MAX_HOURS;


    do{
        if(this->getMaxVac() > VACATION_MAX_HOURS / SICK_LEAVE)
            this->maxVac.setWorkedHours(VACATION_MAX_HOURS);
        do{
            cout << "\n\nYou have " << this->getMaxVac() << " vacation days. Enter how many you would like to take: ";
            cin >> days;
        }while(days > this->getMaxVac() || days < 0);
        
        this->maxVac.setWorkedHours(((this->getMaxVac() - days) * 8) + remaining);
        this->takenVac.setWorkedHours(this->getVacTaken() + days * 8);

    }while(this->getMaxVac() > VACATION_MAX_HOURS / SICK_LEAVE);
}

void TimeOff::updateTimeOff(float months){
    maxVac = checKVacMaxThreshold(months);
    maxSick = maxSick + (months * SICK_LEAVE); 
}