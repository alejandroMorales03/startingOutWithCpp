#include <iostream>
#include <random>

using namespace std;

float* arrayExpander(float* , short);
float* getSample(short);

int main(){
    short size = arc4random_uniform(101);
    float* sample = getSample(size);

    for(short index = 0; index < size; index++){
        cout << *(sample + index) << " ";
    }
    sample = arrayExpander(sample, size);
        cout << "\n\n";

    for(short index = 0; index < size*2; index++){
        cout << *(sample + index) << " ";
    }
    delete[] sample;
    sample = nullptr;
    return 0;
}

/**
 * @brief expands the array by double the size
 * 
 * @param array 
 * @param size 
 * @return float* 
 */
float* arrayExpander(float* array, short size){
    float* biggerArray = new float[size*2];

    for(short index = 0; index < size; index++)
        *(biggerArray + index) = *(array + index);
    
    for(short index = size; index < size*2; index++)
        *(biggerArray + index) = 0;

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