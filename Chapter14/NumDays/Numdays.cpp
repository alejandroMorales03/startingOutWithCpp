#include "Numdays.h"

void Numdays::converter(){
    workDays = workedHours / 8;
}

Numdays::Numdays(float hours){
    workedHours = hours < 0? 0 : hours;
    converter();
}

Numdays::Numdays(){
    workedHours = 0;
    workDays = 0;
}

float Numdays::getWorkedHours()const{
    return workedHours;
}
float Numdays::getWorkDays()const{
    return workDays;
}

void Numdays::setWorkedHours(float hours){
    workedHours = hours < 0? 0 : hours;
    converter();
}

Numdays Numdays::operator+(const Numdays &right){
    Numdays result;
    result.workedHours = this->workedHours + right.workedHours;
    result.converter();
    return result;
}

Numdays Numdays::operator-(const Numdays &right){
    Numdays result;
    result.workedHours = this->workedHours - right.workedHours;
    result.workedHours = result.workedHours < 0? 0 : result.workedHours;
    result.converter();
    return result;
}

Numdays Numdays::operator++(){
    this->workedHours++;
    this->converter();
    return *this;

}
Numdays Numdays::operator--(){
    this->workedHours--;
    this->workedHours = this->workedHours < 0? 0 : this->workedHours;
    this->converter();
    return *this;
}

Numdays Numdays::operator++(int){
    Numdays newObj(*this);
    newObj.converter();

    this->workedHours++;
    this->converter();

    return newObj;
}
Numdays Numdays::operator--(int){
    Numdays newObj(*this);
    newObj.converter();

    this->workedHours--;
    this->workedHours = this->workedHours < 0? 0 : this->workedHours;
    this->converter();

    return newObj;
    
}

