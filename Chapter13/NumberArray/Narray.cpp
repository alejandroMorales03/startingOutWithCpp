#include "Narray.h"
#include <iostream>

using namespace std;

Narray::Narray(int size){
    value_array = new float[size];
    this->size = size;

}
Narray::~Narray(){
    delete[] value_array;
    delete[] sorted_array;

}

void Narray::StoreElmnt(int index, float value){
    if(index < size && index > -1){
        value_array[index] = value;
        sort();
    }
    else{
        cout << "Unreachable Index Position";
    }
}

float Narray::getElmnt(int index) const{
    if(index < size && index > -1)
        return value_array[index];
    else{
        cout << "Unreachable Index Position";
        cout << " PLACEHOLDER: ";
        return 0;
    }

}

float Narray::getAverage() const{
    float average = 0;
    for(short index = 0; index < size; index++){
        average += value_array[index];
    }
    return average/size;
}

 float Narray::getlowest(){
    return  sorted_array[0];
}
float Narray::getHighest(){
    return sorted_array[size - 1];
}
void Narray::sort(){
    sorted_array = new float[size];
    for(short index = 0; index < size; index++){
        sorted_array[index] = value_array[index];
    }

    short minIndex;
    float minValue;

    for(short startScan = 0; startScan < size - 1; startScan++){
        minIndex = startScan;
        minValue = value_array[startScan];

        for(short index = startScan + 1; index < size; index++){
            if(value_array[index] < minValue){
                minValue  = value_array[index];
                minIndex = index;
            }
        }
        value_array[minIndex] = value_array[startScan];
        value_array[startScan] = minValue;
    }
}