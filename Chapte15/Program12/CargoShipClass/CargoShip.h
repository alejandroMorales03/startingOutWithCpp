#ifndef CARGPSHIP_H
#define CARGPSHIP_H

#include "/Users/alejandromorales/projects/Chapte15/Program12/ShipClas/Ship.h"

class CargoShip : public Ship{
    private:
        double tonCap;
    public:
        CargoShip(std::string name, int year, double capacity);
        void setTonCapacity(double tons);
        double getTonCapacity()const;

        void print() override;

        virtual ~CargoShip();

};

#endif