#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <iostream>
#include <chrono>

class ParkingMeter;

class ParkedCar{
    private:
        std::string make;
        std::string model;
        std::string color;
        std::string licenseNumber;
        double minutesParked;

        std::chrono::high_resolution_clock::time_point start_time;

        void startCounter();

    public:
        ParkedCar();
        ParkedCar(std::string, std::string, std::string, std::string);
        
        double getParkedTime();
        std::string getMake() const;
        std::string getModel() const;
        std::string getColor() const;
        std::string getLicNumber() const;






        
};


#endif