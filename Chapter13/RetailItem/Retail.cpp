#include "Retail.h"

Retail::Retail(string desc_u, int units_u, double price_u){
    description = desc_u;
    unitsOnHand = units_u < 0? 0 : units_u;
    price = price_u < 0? 0 : price_u;
}

void Retail::setDesc(string desc_u){
    description = desc_u;
}
void Retail::setUnits(int units_u){
    unitsOnHand = units_u < 0? 0 : units_u;
}
void Retail::setPrice(double price_u){
    price = price_u < 0? 0 : price_u;
}

string Retail::getDesc()const{
    return description;


};
int Retail::getUnits()const{
    return unitsOnHand;

};
double Retail::getPrice()const{
    return price;
}