#include "Officer.h"
#include "Ticket.h"

Officer::Officer(std::string officer, int badge){
    officerName = officer;
    badgeNumber = badge;
    ticketGenerated = false;
}

Officer::Officer(){
    std::cout << "\nMISSING ARGUMENTS 0";
    exit(0);
}

std::string Officer::getName() const{
    return officerName;

}
int Officer::getBadge() const{
    return badgeNumber;

}

bool Officer::inspect(ParkedCar& car, ParkingMeter& meter){
    if(car.getParkedTime() > meter.getPurchasedTime()){
        ticketGenerated = true;
        return true;
    }
    return false;
}

Ticket Officer::generateTicket(ParkedCar& aCar, ParkingMeter& aMeter){
    std::cout << "\nOfficer:               " << officerName;
    std::cout << "\nBadge:                 " << badgeNumber;
    return Ticket(aCar, aMeter);  
}

