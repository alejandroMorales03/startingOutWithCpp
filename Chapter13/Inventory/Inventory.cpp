#include "/Users/alejandromorales/projects/Chapter13/Inventory/Inventory.h"

Inventory::Inventory(){
    itemNumber = 0; 
    quuantity = 0;
    cost = 0;
    totalCost = 0;
}

Inventory::Inventory(int iNum, int iQuan, double iCost){
    itemNumber = iNum <= 0? 0: iNum;
    quuantity = iQuan <= 0? 0: iQuan;
    cost = iCost <= 0? 0: iCost;
    setTotalCost();
}


void Inventory::setItemNumber(int iNum){
    itemNumber = iNum <= 0? 0: iNum;
}
void Inventory::setCost(double iCost){
    cost = iCost <= 0? 0: iCost;
}
void Inventory::setQuantity(int iQuan){
    quuantity = iQuan <= 0? 0: iQuan;
}
void Inventory::setTotalCost(){
    totalCost = cost * quuantity;
}

int Inventory::getItemNum()const{
    return itemNumber;
}
int Inventory::getQuan()const{
    return quuantity;

}
double Inventory::getCost()const{
    return cost;

}
double Inventory::getTotalCost(){
    setTotalCost();
    return totalCost;
}



