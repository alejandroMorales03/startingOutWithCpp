
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double recLen, double recWidth){
    if(recLen < 0 || recWidth < 0)
        throw std::runtime_error("ERROR TYPE| NEGATIVE WIDTH OR/AND LENGTH ARE INVALID");
    length = recLen;
    width = recWidth;
    calcArea();
}

void Rectangle::calcArea(){
    area = length * width;
}

double Rectangle::getLength()const{return length;}
double Rectangle::getWidth()const{return width;}

Rectangle::~Rectangle(){};

