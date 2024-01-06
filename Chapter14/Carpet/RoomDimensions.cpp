#include "RoomDimensions.h"

RoomDimensions::RoomDimensions(int lengthFeet, int lengthInches, int WidthFeet, int WidthInches){
    roomLength = FeetInches(lengthFeet, lengthInches);
    roomWidth = FeetInches(WidthFeet, WidthInches);
}

FeetInches RoomDimensions::getArea(){
    return roomLength * roomWidth;
}