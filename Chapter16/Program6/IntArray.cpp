#include "IntArray.h"

void IntArray::allocation(){
    if(this->size <= 0){
        throw OutOfBoundsException(size);
    }

    else{
        ptr = new int[size];
    }

}
IntArray::IntArray(int size) : size(size) {
    allocation();
}

IntArray::IntArray(int size, int value) : size(size) {
    allocation();

    for(int index = 0; index < size; index++){
        ptr[index] = value;
    }
}

int IntArray::getSize() const{
    return this->size;
}

int IntArray::getValueAtIndex(int index) const{
    if(index >= size || index < 0)
        throw OutOfBoundsException(index);
    return ptr[index];
}

int IntArray::getLocation(int value){
    int index = 0;

    while(index < size && ptr[index] != value){
        index++;
    }

    return index == size? -1 : index;
    
}

void IntArray::setValueAtIndex(int index, int value){
    if(index >= size || index < 0)
        throw OutOfBoundsException(index);

    else ptr[index] = value;

}

void IntArray::display(){
    std::cout << "\n";
    for(int index = 0; index < size; index++){
        std::cout << ptr[index] << " ";
    }
}

IntArray::~IntArray(){
    delete[] ptr;
    ptr = nullptr;
}


IntArray::OutOfBoundsException::OutOfBoundsException(int size){
    if(size <= 0)
        message = "INVALID ARRAY SIZE";
    else    
        message = "INACCESSIBLE LOCATION";
}

std::string IntArray::OutOfBoundsException::getErrorMessage()const{
    return message;
}