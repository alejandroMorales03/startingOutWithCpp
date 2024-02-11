#include "MilTime.h"
#include <sstream>

MilTime::MilTime(int userHour, int userSec) : Time(userHour/100, userHour%100, userSec){};

std::string MilTime::getTime()const{
    std::stringstream returnValue;
    returnValue << std::setfill('0') << std::setw(4) << std::to_string(getHour()) + std::to_string(getMinute()) << " " <<  std::to_string(getSecond());
    return returnValue.str();

}

MilTime::~MilTime(){}