#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Populator(short[], short[],short);
void Printer(short[], short);
void BubbleSort(short[], short);
void SelectionSort(short[], short);

int main(){
    short array_one[8], array_two[8];
    Populator(array_one, array_two, 8);

    Printer(array_one, 8);
    BubbleSort(array_one, 8);
    cout << "\n\n";
    Printer(array_two, 8);
    SelectionSort(array_two, 8);
    return 0;

}

/**
 * @brief Populates two array with the same size random values
 * 
 * @param array1 
 * @param array2 
 * @param size 
 */
void Populator(short array1[], short array2[], short size){
    srand(time(0));
    for(short index = 0; index < size; index++){
        array1[index] = array2[index] = (rand() % (1000 - 0 + 1) + 0);
    }
}

/**
 * @brief Prints the values of a given array
 * 
 * @param array 
 * @param size 
 */
void Printer(short array[], short size){
    for(short index = 0; index < size; index++){
        cout << array[index] << " ";
    }
}

/**
 * @brief Uses bubble sort algorithm to sort an array
 * 
 * @param array 
 * @param size 
 */
void BubbleSort(short array[], short size){
    bool swap;
    short temp;
    do{
        swap = false;
        for(short index = 0; index < size - 1; index++){
            if(array[index + 1] > array[index]){
                temp = array[index + 1];
                array[index + 1] = array[index];
                array[index] = temp;
                swap = true;
            }
        }

        cout << "\n";
        Printer(array, 8);

    }while(swap);

}

/**
 * @brief Uses selection sort algorithm to sort a given array
 * 
 * @param array 
 * @param size 
 */
void SelectionSort(short array[], short size){
    short minIndex, minValue;
    for(short startScan = 0; startScan < size - 1; startScan++){
        minIndex = startScan;
        minValue = array[startScan];
        
        for(short index = startScan + 1; index < size; index++){
            if(array[index] < minValue){
                minValue = array[index];
                minIndex = index;
            }

        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
        cout << "\n"
;        Printer(array, size);
    }
}
