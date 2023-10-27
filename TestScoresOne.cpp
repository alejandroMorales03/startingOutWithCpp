#include <iostream>
#include <vector>

using namespace std;

short getSize();
void getScores(float *, short);
void Sorter(float*, short);
float calculateAverage(float const*, short);

int main(){
    short size = getSize();
    float* scores = new float[size];

    if(scores){
        getScores(scores, size);
        Sorter(scores, size);

        cout << "\n";
        for(short index = 0; index < size; index++)
            cout << *(scores + index) << " ";
        
        float average = calculateAverage(scores, size);
        cout << "\n\nAverage: " << average << "\n";
        delete [] scores;
        scores = nullptr;
    }
    return 0;
}

/**
 * @brief Get the Size object
 * 
 * @return short 
 */

short getSize(){
    short size;
    do{
        cout << "\nEnter the numnber of tests scores you wish to enter: ";
        cin >> size;
        if(size < 1)
            cout << "\nThe number of test scores must be at least 1\n";
    }while(size < 1);
    return size;
}

/**
 * @brief Get the Scores object
 * 
 * @param ptr 
 * @param size 
 */
void getScores(float* ptr, short size){
    cout << "\nEnter the scores: \n\n";

    for(short count = 0; count < size; count++){
        do{
            cout << "Score " << (count + 1) << ": ";
            cin >> *(ptr + count);
            if(*(ptr + count) < 0)
                cout << "\nINVALID INPUT\n\n";
        }while(*(ptr + count) < 0);
    }
}

/**
 * @brief Sorts the array that ptr points to using selection sort algorithm
 * 
 * @param ptr 
 * @param size 
 */
void Sorter(float* ptr, short size){
    float maxValue;
    short maxIndex;

    for(short startScan = 0; startScan < size - 1; startScan++){
        maxValue = *(ptr + startScan);
        maxIndex = startScan;

        for(short index = startScan + 1; index < size; index++){
            if(*(ptr + index) > maxValue){
                maxValue = *(ptr+index);
                maxIndex = index;
            }
        }

        *(ptr + maxIndex) = *(ptr + startScan);
        *(ptr + startScan) = maxValue;
    }
}

/**
 * @brief Calculates the average of the values stored in the array ptr points to
 * 
 * @param ptr 
 * @param size 
 * @return float 
 */
float calculateAverage(float const* ptr, short size){
    short drop;
    float total = 0;
    do{
        cout << "\n\nWould you like to drop the lowest score\n1. No\n2. Yes\n\nSelection: ";
        cin >> drop;
        drop--;
        if(!(drop >= 0 && drop <= 1))
            cout << "\nINVALID SELECTION\n";
    }while(!(drop >= 0 && drop <= 1));

    if(drop)
        size--;

    for(short index = 0; index < size; index++){
        total += *(ptr + index);
    }
    return total/size;
}