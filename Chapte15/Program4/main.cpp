#include <iostream>
#include "/Users/alejandromorales/projects/Chapte15/Program4/MilTimeClass/MilTime.h"
#include "/Users/alejandromorales/projects/Chapte15/Program4/TimeClass/Time.h"


int main(){
    MilTime test2Time(2059, 59);

    std::cout << test2Time.getMilHour() << "\n";
    std::cout << test2Time.getStdHour() << "\n";

    Time test1Time(17, 50, 60, "AM");    
    std::cout << test1Time.getTime();


}