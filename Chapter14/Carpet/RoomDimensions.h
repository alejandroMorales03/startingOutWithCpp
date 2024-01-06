#ifndef ROOMDIMENSIONS_H
#define ROOMDIMENSIONS_H

#include "/Users/alejandromorales/projects/Chapter14/FeetInches/FeetInches.h"

class RoomDimensions{
    private:
        FeetInches roomLength;
        FeetInches roomWidth;

    public:
        RoomDimensions(int = 0, int = 0, int = 0, int = 0);
        FeetInches getArea();
        

};

#endif