#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

float* getSample(short);
float* reverseArray(float[], short);

int main(){
    srand(time(0));
    short size = arc4random_uniform(101);
    float* sample = getSample(size);
    
    cout << "\n";
    for(short index = 0; index < size; index++)
        cout << *(sample + index) << " ";
    cout << "\n\n";
    sample = reverseArray(sample, size);
    for(short index = 0; index < size; index++)
        cout << *(sample + index) << " ";
    cout << "\n\n";

    delete[] sample;
    sample = nullptr;

    return 0;
}

/**
 * @brief Gets the reverse of the given array
 * 
 * @param array 
 * @param size 
 * @return float* 
 */
float* reverseArray(float array[], short size){
    vector<float> list(array, array + size);
    reverse(list.begin(), list.end());

    for(short index = 0; index < size; index++)
        array[index]= list[index];

    return array;
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

