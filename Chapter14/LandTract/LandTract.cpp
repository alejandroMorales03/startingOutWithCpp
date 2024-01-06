#include "LandTract.h"
#include "/Users/alejandromorales/projects/Chapter14/FeetInches/FeetInches.h"

LandTract::LandTract(FeetInches length, FeetInches width){
    this->length = length;
    this->width = width;
}

FeetInches LandTract::getArea(){
    return (length * width);
}

std::ostream &operator<<(std::ostream& strm, const LandTract& obj){
    std::cout << "\nLength: " << obj.length;
    std::cout << "\nWidth: " << obj.width;
    return strm;
}

bool LandTract::operator==(LandTract& otherMeasurement){
    return this->getArea() == otherMeasurement.getArea();
}

