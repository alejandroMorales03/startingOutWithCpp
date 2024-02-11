#include "Time.h"

Time::Time(int userHour, int userMinute, int userSec, std::string timeOfDay):
    MAX_HOUR(23), MAX_MIN_SEC(59), MIN(0){

        if(timeOfDay.empty()){
            if(userHour < 12) 
                timeSetting = "AM";
            else 
                timeSetting = "PM";
        }
        else{
            if((userHour < 12 && timeOfDay == "PM") || (userHour >= 12 && timeOfDay == "AM"))
                throw InvalidTimeSetting(userHour, timeOfDay);
            else
                timeSetting = timeOfDay;
        }
        

        if(userHour < MIN || userHour > MAX_HOUR)     
            throw BadHour(userHour); 
        else 
            hour = userHour;
        
        if(userMinute < MIN || userMinute > MAX_MIN_SEC)
            throw BadMinute(userMinute);
        else
            minute = userMinute;

        if(userSec < MIN || userSec > MAX_MIN_SEC)
            throw BadSecond(userSec);
        else
            second = userSec;  
}

int Time::getHour()const{
    return hour;
}
int Time::getMinute()const{
    return minute;
}
int Time::getSecond()const{
    return second;
}

std::string Time::getTimeSetting() const{
    return timeSetting;
}

Time::~Time(){}