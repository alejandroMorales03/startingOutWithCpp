#include "MilTime.h"

MilTime::MilTime(int militaryhours, int militarseconds) : Time(militaryhours /100, militaryhours % 100, militarseconds){
    milhour = militaryhours;
    milseconds = militarseconds;

}

std::string MilTime::getMilHour()const{
    return std::to_string(milhour) + " " + std::to_string(milseconds);
}

std::string MilTime::getStdHour(){
    return getTime();
}

