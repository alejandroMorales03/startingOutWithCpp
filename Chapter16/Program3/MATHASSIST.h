#ifndef MATHASSIST_H
#define MATHASSIST_H

#include <iostream>

template <class Type>
Type lowest(Type argOne, Type argTwo){
    return argOne < argTwo? argOne : argTwo;
}
template <class Type>
Type highest(Type argOne, Type argTwo){
    return argOne > argTwo? argOne : argTwo;
}

template <class Type>
Type absoluteVal(Type argOne){
    return argOne < 0? -argOne : argOne;
}

template <class Type, class TypeOther>

TypeOther total(Type size, TypeOther returnValueType){
    TypeOther sum = 0;
    TypeOther value;

    std::cout << "\n";
    std::cout << "Enter " << size  << " values: ";
    
    for(int index = 0; index < size; index++){
        std::cin >> value;
        sum = sum + value;
    }

    return sum;
}


#endif