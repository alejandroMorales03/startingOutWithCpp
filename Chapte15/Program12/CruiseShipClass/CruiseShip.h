#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "/Users/alejandromorales/projects/Chapte15/Program12/ShipClas/Ship.h"
class CruiseShip : public Ship{
    private: 
        int maxPassengers;
    public:
        CruiseShip(std::string name, int year, int passengers);

        void setMaxPassengers(int maxPass);
        int getMaxpassengers()const;
        
        void print() override;
        virtual ~CruiseShip();

};

#endif