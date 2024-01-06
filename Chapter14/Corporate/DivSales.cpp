#include "DivSales.h"

double DivSales::totalCorporateSales = 0;

DivSales::DivSales(double Q1, double Q2, double Q3, double Q4){
    quarterlySales[0] = Q1 > 0? Q1 : 0;
    quarterlySales[1] = Q2 > 0? Q2 : 0;
    quarterlySales[2] = Q3 > 0? Q3 : 0;
    quarterlySales[3] = Q4 > 0? Q4 : 0;

    for(short index = 0; index < QUARTERS; index++)
        totalCorporateSales += quarterlySales[index];
}

double DivSales::inspectQuarter(int index){
    if(index < 4 && index > -1)
        return quarterlySales[index];
    else
        return 0;

}

double DivSales::getTotalSales(){
    return totalCorporateSales;
}