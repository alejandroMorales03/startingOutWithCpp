#include "Car.h"

Car::Car(int yearMode_u, string make_u){
    yearModel = yearMode_u; 
    make = make_u;
    speed = 0;
}

string Car::getMake()const{
    return make;

}

int Car::getYearModel()const{
    return yearModel;

}
float Car::getSpeed()const{
    return speed;

}
void Car::accelerate(){
    speed += 5;

}
void Car::brake(){
    speed = speed - 5 < 0? 0 : speed - 5;
}