#ifndef RETAIL_H
#define RETAIL_H

#include <string>
using namespace std;

class Retail{
    private:
        string description;
        int unitsOnHand;
        double price;

    public:
        Retail(string desc_u = " ", int units_u = 0, double price_u = 0);

        void setDesc(string desc_u);
        void setUnits(int units_u);
        void setPrice(double price_u);

        string getDesc()const;
        int getUnits()const;
        double getPrice()const;
};

#endif