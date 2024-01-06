#ifndef OFFICER_H
#define OFFICER_H

#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "Ticket.h"

class Officer{
    private:
        std::string officerName;
        int badgeNumber;
        bool ticketGenerated;

    public:
        Officer(std::string, int);
        Officer();

        std::string getName() const;
        int getBadge() const;

        bool inspect(ParkedCar&, ParkingMeter&);
        Ticket generateTicket(ParkedCar&, ParkingMeter&);



};

#endif