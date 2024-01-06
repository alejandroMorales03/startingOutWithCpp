#ifndef LANDTRACT_H
#define LANDTRACT_H

#include <iostream>
#include "/Users/alejandromorales/projects/Chapter14/FeetInches/FeetInches.h"

class LandTract{
    private:
        FeetInches length;
        FeetInches width;

    public:
        LandTract(FeetInches, FeetInches);
        FeetInches getArea();

        friend std::ostream &operator<<(std::ostream&, const LandTract&);
        bool operator==(LandTract&);

        

};


#endif