#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
using namespace std;

class Inventory{
    private:
        int itemNumber;
        int quuantity;
        double cost;
        double totalCost;

        void setTotalCost();
    
    public:
        Inventory();
        Inventory(int iNum, int iQuan, double iCost);

        void setItemNumber(int iNum);
        void setQuantity(int iQuan);
        void setCost(double iCost);

        int getItemNum()const;
        int getQuan()const;
        double getCost()const;
        double getTotalCost();
};

#endif