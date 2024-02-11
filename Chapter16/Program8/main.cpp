#include <iostream>
#include "SimpleVector.h"

int main(){

    //Vector Constructor Using Give Value
    int SIZE = 10;
    std::cout << "\nCREATING VECTOR\n";
    SimpleVector<char> myvector(SIZE, 'A');
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();

    std::cout << "\n\nPUSHING ONE ELEMENT\n";
    myvector.push('Z');
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();    

    std::cout << "\n\nPOPPING THREE ELEMENT\n";
    myvector.pop();
    myvector.pop();
    myvector.pop();
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();

    std::cout << "\n\nSHRINKING\n";
    myvector.shrink();
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();

    std::cout << "\n\nPUSHING ONE ELEMENT\n";
    myvector.push('B');
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();  
    
    std::cout << "\n\nSEARCHING FOR ONE ELEMENT\n";
    *(myvector.search('B')) = 'W';
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();  
    
    std::cout << "\n\nCLEARING VECTOR\n";
    myvector.clear();
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();

    std::cout << "\n\nPUSHING ONE ELEMENT\n";
    myvector.push('C');
    myvector.display();
    std::cout << "\n" << "Capacity: " << myvector.capacity() << "   Elements: " << myvector.elements();  


    return 0;
}