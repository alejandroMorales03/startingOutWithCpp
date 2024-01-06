#ifndef ROOMCARPET_H
#define ROOMCARPET_H

#include "RoomDimensions.h"

class RoomCarpet{
    private:
        RoomDimensions room;
        double price;

    public:
        RoomCarpet(int = 0, int = 0, int = 0, int = 0, double = 0);
        void setDimensions(int = 0, int = 0, int = 0, int = 0);
        void setPrice(double = 0);
        double getTotal();

};

#endif
