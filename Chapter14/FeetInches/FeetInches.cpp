#include "FeetInches.h"
#include <iostream>

FeetInches::FeetInches(int feet, int inches){
    this->feet = feet < 0? 0 : feet;
    this->inches = inches < 0? 0 : inches;

    if(this->inches >= 12){
        this->feet += this->inches / 12;;
        this->inches %= 12;
    }

}

void FeetInches::printMeasurement(std::string del){
    std::cout << feet << "' " << inches << del;
}

FeetInches FeetInches::operator*(const FeetInches& otherMeasurement){
    return FeetInches(0, ((this->feet * 12 + this->inches) * (otherMeasurement.feet * 12 + otherMeasurement.inches)));
}

double FeetInches::operator*(double doubleObj){
    return feet * doubleObj + (inches/inInFeet) * doubleObj;
}

std::istream& operator>>(std::istream& strm, FeetInches& input){
    std::cout << "\nEnter feet: ";
    int feet;
    std::cin >> feet;
    std::cout << "Enter inches: ";
    int inches;
    std::cin >> inches;

    input = FeetInches(feet, inches);
    return strm;   
}

std::ostream &operator<<(std::ostream & strm, const FeetInches &output){
    std::cout << output.feet << "' " << output.inches;
    return strm;
}

bool FeetInches::operator==(const FeetInches& otherMeasurement){
    return this->feet == otherMeasurement.feet && this->inches == otherMeasurement.inches;
    
}