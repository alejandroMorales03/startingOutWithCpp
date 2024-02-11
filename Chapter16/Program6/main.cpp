#include <iostream>
#include "IntArray.h"


//Fully functional and tested/ One thing to improve is input reading. if user enters a different data type it leads to unexpected results
using namespace std;
int main(){

    IntArray* myTestArray = nullptr;

    bool trigger = true;
    int size;
    int value;
    int index;
    
    cout << "\nEnter a size for the array: ";
    cin >> size;

    do{
        try{
            myTestArray = new IntArray(size);
            trigger = false;
        }catch(IntArray::OutOfBoundsException excp){
            cout << "\n" << excp.getErrorMessage();

            cout << "\nEnter a size greater than 0: ";
            cin >> size;
        }
    }while(trigger);

    trigger = true;

    delete myTestArray;
    myTestArray = nullptr;

    cout << "\nEnter a value to store in all elements of the array: ";
    cin >> value;

    do{
        try{
            myTestArray = new IntArray(size, value);
            trigger = false;
        }catch(IntArray::OutOfBoundsException excp){
            cout << "\n" << excp.getErrorMessage();

            cout << "\nEnter a size greater than 0: ";
            cin >> size;
        }
    }while(trigger);

    myTestArray->display();

    cout << "\nEnter a location to be modfied: ";
    cin >> index;
    cout << "Enter the value to be stored: ";
    cin >> value;

    trigger = true;
    do{
        try{
            myTestArray->setValueAtIndex(index, value);
            myTestArray->display();
            trigger = false;
        }catch(IntArray::OutOfBoundsException excp){

            cout << "\n" << excp.getErrorMessage();

            cout << "\nEnter a valid location: ";
            cin >> index;

        }

    }while(trigger);

    trigger = true;

    cout << "\nEnter a location to retrive: ";
    cin >> index;

    do{

        try{
            cout << myTestArray->getValueAtIndex(index);
            trigger = false;
        }catch(IntArray::OutOfBoundsException excp){
            cout << "\n" << excp.getErrorMessage();

            cout << "\nEnter a valid location: ";
            cin >> index;


        }

    }while(trigger);


    std::cout << "\nEnter a number to be searched for: ";
    cin >> value;

    cout << "\n" << myTestArray->getLocation(value);

    cout << "\n" << myTestArray->getSize() << "\n\n";

    delete myTestArray;
    myTestArray = nullptr;

    return 0;
}