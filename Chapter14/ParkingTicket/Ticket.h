#ifndef TICKET_H
#define TICKET_H

#include "ParkingMeter.h"
#include "ParkedCar.h"

class Ticket{
    private:
        double fine;
        ParkedCar car;
        ParkingMeter meter;

    public:
        Ticket(ParkedCar, ParkingMeter);
        double getFine();
        void printTicket();


};

#endif