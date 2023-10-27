#include <iostream>
#include <random>

using namespace std;

float* arrayShifter(float* , short);
float* getSample(short);

int main(){
    short size = arc4random_uniform(101);
    float* sample = getSample(size);

    for(short index = 0; index < size; index++){
        cout << *(sample + index) << " ";
    }
    sample = arrayShifter(sample, size);
        cout << "\n\n";

    for(short index = 0; index < size + 1; index++){
        cout << *(sample + index) << " ";
    }
    delete[] sample;
    sample = nullptr;
    return 0;
}

/**
 * @brief Shifts all the element to the right by one
 * 
 * @param array 
 * @param size 
 * @return float* 
 */
float* arrayShifter(float* array, short size){
    float* biggerArray = new float[size*1];

    for(short index = 1; index < size + 1; index++)
        biggerArray[index] = array[index - 1];

    return biggerArray;
}

/**
 * @brief Get the Sample object
 * 
 * @param size 
 * @return float* 
 */

float* getSample(short size){
    float* sample = new float[size];
    for(short index = 0; index < size; index++){
        sample[index] = arc4random_uniform(101);
    }
    return sample;
    

}