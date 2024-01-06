#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>

class FeetInches{
    
    private:
        static const int inInFeet = 12;
        int feet;
        int inches;

    public: 
        FeetInches(int = 0, int = 0 );
        void printMeasurement(std::string del = "");

        FeetInches operator*(const FeetInches&);
        double operator*(double);
        bool operator==(const FeetInches& otherMeasurement);
        
        friend std::istream &operator>>(std::istream &, FeetInches &input);
        friend std::ostream &operator<<(std::ostream &, const FeetInches &output);
};

#endif