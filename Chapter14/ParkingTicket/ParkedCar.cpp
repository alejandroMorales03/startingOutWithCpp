#include "ParkedCar.h"
#include <chrono>
#include <iostream>

ParkedCar::ParkedCar(std::string make, std::string model, std::string color, std::string licenseNumber){
    this->make = make;
    this->model = model;
    this->color = color;
    this->licenseNumber = licenseNumber;
    startCounter();
}

ParkedCar::ParkedCar(){
    std::cout << "\nMISSING ARGUMENTS 2";
    exit(0);

}



void ParkedCar::startCounter(){
    start_time = std::chrono::high_resolution_clock::now();
}

double ParkedCar::getParkedTime(){
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    this->minutesParked = elapsed_time.count();
    return this->minutesParked;
}


std::string ParkedCar::getMake() const{
    return make;
}
std::string ParkedCar::getModel() const{
    return model;
}
std::string ParkedCar::getColor() const{
    return color;
}
std::string ParkedCar::getLicNumber() const{
    return licenseNumber;
}
