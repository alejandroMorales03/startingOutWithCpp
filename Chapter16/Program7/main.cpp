#include <iostream>
#include "/Users/alejandromorales/projects/Chapter16/Program7/TestScores.h"
//Program works fine. Exceptions were not handlled on purpose

int main(){

    int size;
    float* ptr = nullptr;
    TestScores* testptr = nullptr;



        std::cout << "\nHow many scores do you want to process: ";
        std::cin >> size;

        ptr = new float[size];
 



    for(int index = 0; index < size; index++){
        std::cout << "\nEnter score: ";
        std::cin >> ptr[index];
    }
    
    testptr = new TestScores(ptr, size);
    std::cout << "Average: " << testptr->average();
    




    testptr = new TestScores(ptr, size - size);

    delete testptr;
    testptr = nullptr;
    delete[] ptr;
    ptr = nullptr;

    
    



    return 0;
}