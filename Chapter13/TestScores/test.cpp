#include "test.h"
#include <iostream> 

const float test::MAX_SCORE = 100;
const float test::MIN_SCORE = 0;

using namespace std;
test::test(int size){
    this->size = size;
    ptr_test = new float[size];
    for(short index = 0; index < size; index++){
        ptr_test[index] = 0;
    }
}

scoreSignal test::getTest(int index){
    if(index < 0 || index > size - 1){
        myIndexSignal.condition = false;
        myIndexSignal.score = ptr_test[0];
    }
    else{
        myIndexSignal.condition = true;
        myIndexSignal.score = ptr_test[index];
    }

    return myIndexSignal;


}

void test::setTest(int index, float score){
    if((score < MIN_SCORE || score > MAX_SCORE) || (index < 0 || index > size - 1))
        inputValidation(index, score);
    ptr_test[index] = score;
}

void test::inputValidation(int index, float value){

    if(value < MIN_SCORE || value > MAX_SCORE){
        cout << "\nINVALID SCORE DETECTED: ";
        cout << "\n\nENTER A SCORE IN THE RANGE [" << MIN_SCORE << "-" << MAX_SCORE << "]";
        cout << "\nSCORE: ";
        cin >> value;
    }
    if(index < 0 || index > size - 1){
        cout << "\nINVALID TEST NUMBER DETECTED: ";
        cout << "\n\nENTER A TEST IN THE RANGE [" << 1 << "-" << size << "]";
        cout << "\nTEST: ";
        cin >> index;
        index--;
    }
    setTest(index, value);
}

float test::getAverage() const{
    float total = 0;
    for(short index = 0; index < size; index++){
        total += ptr_test[index];
    }
    return total/size;
}

test::~test(){
    delete[] ptr_test;
}

