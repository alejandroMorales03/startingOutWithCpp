#include "Circle.h"
#include <iostream>

const double Circle::PI = 3.14159;
Circle::Circle(double xCent, double yCent, double radius){
    if(radius < 0)
        throw std::runtime_error("ERROR TYPE| NEGATIVE RADIUS IS INVALID");
    this->radius = radius;
    calcArea();
}

void Circle::calcArea(){
    area = PI * radius * radius;
}

double Circle::getXCoordinate()const{return centerX;}
double Circle::getYCoordinate()const{return centerY;}

Circle::~Circle(){}