#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void populateArray(short[], short );
short bubbleSort(short[], short);
short selectionSort(short[], short);

int main(){
    const short size = 20;
    short array[size];
    
    populateArray(array, size);
    cout << "\n";
    for(short holder : array)
        cout << holder << " ";
    cout << "\nBubble Sort: " << bubbleSort(array, size) << "\n";
    for(short holder : array)
        cout << holder << " ";

    populateArray(array, size);
    cout << "\n\n";
    for(short holder : array)
        cout << holder << " ";
    cout << "\nSelection Sort: " << selectionSort(array, size) << "\n";
    for(short holder : array)
        cout << holder << " ";
    cout << "\n\n";
    return 0;
}
/**
 * @brief populates an array with size integers
 * 
 * @param list 
 * @param size 
 */
void populateArray(short list[], short size){
    srand(time(0));
    for(short index  = 0; index < size; index++){
        list[index] = (rand() % (1000 - 0 + 1) + 0);
    }

}

/**
 * @brief Ues bubble sort algorithm to sort the array
 * 
 * @param list 
 * @param size 
 * @return short 
 */
short bubbleSort(short list[], short size){
    bool swap;
    short temp, count = 0;

    do{
        swap = false;
        for(short index = 0; index < size - 1; index++)
            if(list[index + 1] < list[index]){
                temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
                swap = true;
                count++;
            }


    }while(swap);
    return count;

}

/**
 * @brief Uses selection sort algorithm to sort the given array
 * 
 * @param list 
 * @param size 
 * @return short 
 */
short selectionSort(short list[], short size){
    short count = 0, minIndex, minValue;
    for(short startscan = 0; startscan < size - 1; startscan++){
        minIndex = startscan;
        minValue = list[startscan];

        for(short index = startscan + 1; index < size; index++){
            if(list[index] < minValue){
                minValue = list[index];
                minIndex = index;
                count++;
            }
        }

        list[minIndex] = list[startscan];
        list[startscan] = minValue;
    }
    return count;


}
