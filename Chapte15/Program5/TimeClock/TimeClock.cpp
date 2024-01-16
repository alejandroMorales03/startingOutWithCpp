#include "TimeClock.h"

TimeClock::TimeClock(int start, int end) : startingTime(start, 0), endingTime(end, 0){ 
    elapsed = end - start;
}

std::string TimeClock::getElapsed(){
    std::string timePassed = std::to_string(elapsed/100) + " hours, " + std::to_string(elapsed % 100) + " minutes";
    return timePassed;
}

