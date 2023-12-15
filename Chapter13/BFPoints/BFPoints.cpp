#include "BFPoints.h"

BFPoints::BFPoints(){
    temp = 0;
}

BFPoints::BFPoints(float temp_u){
    temp = temp_u;
}

void BFPoints::setTemp(float temp_u){
    temp = temp_u;
}
        
float BFPoints::getTemp()const{
    return temp;
}

bool BFPoints::isEthylFreezing()const{
    return temp <= ETHYL_ALC_F;
}

bool BFPoints::isEthylBoining()const{
    return temp >= ETHYL_ALC_B;
}

bool BFPoints::isOxyFreezing()const{
    return temp <= OXY_F;
}

bool BFPoints::isOxyBoiling()const{
    return temp >= OXY_F;
}

bool BFPoints::isWatFreezing()const{
    return temp <= WAT_F;
}

bool BFPoints::isWatBoiling()const{
    return temp >= WAT_B;
}

