#include "RoomCarpet.h"

RoomCarpet::RoomCarpet(int lengthFeet, int lengthInches, int WidthFeet, int WidthInches, double pricing){
    setDimensions(lengthFeet, lengthInches, WidthFeet, WidthInches);
    setPrice(pricing);
}

void RoomCarpet::setDimensions(int lengthFeet, int lengthInches, int WidthFeet, int WidthInches){
    room = RoomDimensions(lengthFeet, lengthInches, WidthFeet, WidthInches);
}
void RoomCarpet::setPrice(double pricing){
    price = pricing < 0? 0 : pricing;
}
double RoomCarpet::getTotal(){
    return room.getArea() * price;
}