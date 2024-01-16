#include "Time.h"
#include <iostream>
#include <iomanip>
#include <sstream>


void Time::changeMeridian(){
    meridian = meridian == "AM" ? "PM" : "AM";
    

}

void Time::setHour(int hour_u){
    if(hour_u == 0){
        hour = 12;
        meridian = "AM";
    }
    else if(hour_u > MAX_HOUR/2){
        hour = hour_u - MAX_HOUR/2;
        changeMeridian();
    }
    else{
        hour = hour_u;
    }
}

Time::Time(int hour_u, int min_u, int second_u, std::string meridian_u){
    if(hour_u < MIN || hour_u >= MAX_HOUR || min_u < MIN || min_u > MAX_MINUTE_SEC || second_u < MIN || second_u > MAX_MINUTE_SEC){
        throw std::runtime_error("INVALID DATE DETECTED");
    }
    hour = 12, minute = 0, second = 0;
    meridian = meridian_u;
    setHour(hour_u);
    minute = min_u;
    second = second_u;
}

std::string Time::getTime(){
    return formatTime();
}

std::string Time::formatTime(){
       std::ostringstream timeStream;

    timeStream << std::setw(2) << std::setfill('0') << hour << ":"
               << std::setw(2) << std::setfill('0') << minute << ":"
               << std::setw(2) << std::setfill('0') << second << meridian;
    return timeStream.str();
}

