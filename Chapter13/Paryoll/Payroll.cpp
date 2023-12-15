#include <iostream>
#include "Payroll.h"
using namespace std;

const float Payroll::MAX_HOUR = 60;
Payroll::Payroll(){
    hours_worked = 0;
    hourlyPayRate =0;
}
Payroll::Payroll(float hours, float perHour){
    hours_worked = hours;
    hourlyPayRate = perHour;
}

void Payroll::setHours(float& hours){
    if(checkBounds(hours, 0, 60, false,true))
        hours_worked = hours;
}
void Payroll::setPay(float perHour){
    if(checkBounds(perHour, 0, perHour, true, false))
        hourlyPayRate = perHour;
}

bool Payroll::checkBounds(float &check, float low, float high, bool pay, bool hours){
    if(check < low || check > high){
        if(pay){
            cout << "\nINVALID VALUE. MUST BE GREATER THAN 0: ";
            cin >> check;
            setPay(check);
        }
        if(hours){
            cout << "\nINVALID VALUE. MUST BE [" << low << " - " << high << "]: ";
            cin >> check;
            setHours(check);
        }
    }
    return true;
}



float Payroll::getGross(){
    return hours_worked * hourlyPayRate;
}