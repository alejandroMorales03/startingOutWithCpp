#include "circle.h"
#include <cmath>

const float circle::PI = 3.14159;

circle::circle(){
    radius = 0;
}

circle::circle(float rad){
    if(rad < 0)
        circle();
    else
        radius = rad;
}

void circle::setRadius(float rad){
    if(rad < 0)
        circle();
    else
        radius = rad;
}

float circle::getRadius()const{
    return radius;
}

float circle::getArea()const{
    return PI * pow(radius, 2);
}

float circle::getDiameter()const{
    return 2 * radius;
}

float circle::getCircumference()const{
    return 2 * PI * radius;
}