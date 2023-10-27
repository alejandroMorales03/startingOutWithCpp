#include <iostream>

using namespace std;

float findMedian(float[], short);
float* getSample(short);
int main(){
    srand(time(0));
    short size = (rand() % (20 - 0 + 1) + 0);
    float* sample = getSample(size);
    cout << "\nThe median is " << findMedian(sample, size) << "\n\n";
    delete[] sample;
    sample = nullptr;
    return 0;
}

/**
 * @brief Finds the median of a sample list
 * 
 * @param array 
 * @param size 
 * @return float 
 */
float findMedian(float array[], short size){
    float median;

    if(size % 2 != 0)
        median = *(array + (size/2));
    else 
        median = (*(array + size/2) + *(array + size/2 - 1)) / 2.0;

    return median;
}

/**
 * @brief Get the Sample object
 * 
 * @return float* 
 */
float* getSample(short size){
    float* array = new float[size];
    cout << "\n";
    for(short count = 1; count <= size; count++){
        array[count - 1] = (rand() % (20 - 0 + 1) + 0);
        cout << array[count - 1] << " ";
    }
    return array;
}
