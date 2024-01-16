#ifndef SHIP_H
#define SHIP_H

#include <iostream>

class Ship{
    private:
        static int MIN_YEAR;
        std::string shipName;
        int yearBuilt;
    public:
        Ship(std::string name, int year);
        
        void setName(std::string name);
        void setYear(int year);

        std::string getName();
        int getYear();

        virtual void print();
        virtual ~Ship();


};

#endif