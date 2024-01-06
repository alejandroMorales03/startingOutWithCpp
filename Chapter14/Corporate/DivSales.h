#ifndef DIVSALES_H
#define DIVSALES_H

#include <iostream>

class DivSales{
    
    private:
        static double totalCorporateSales;
        static const int QUARTERS = 4;
        double quarterlySales[QUARTERS];

    public:
        DivSales(double = 0, double = 0, double = 0, double = 0);
        double inspectQuarter(int);
        double static getTotalSales();
    
};

#endif