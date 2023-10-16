#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void populateArray(short[], short);
short linearSearch(short[], short, short);
short binarySearch(short[], short, short);
int main(){
    const short size = 20;
    short array[size];
    short search;
    populateArray(array, size);
    for(short holder : array)
        cout << holder << " ";

    cout << "\nEnter search value: ";
    cin >> search;

    cout << "\nLinear Search: " << linearSearch(array, size, search);
    cout << "\nBinary Search: " << binarySearch(array, size, search);
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
 * @brief finds a given value using linear search and counts how many comparisons are performed
 * 
 * @param list 
 * @param size 
 * @param search 
 * @return short 
 */
short linearSearch(short list[], short size, short search){
    short count = 0;
    bool found = false;
    for(short index  = 0; index < size && !found; index++, count++){
        if(search == list[index])
            found = true;

    }
    return count;
}

/**
 * @brief finds a given value using binary search and counts how many comparisons are performed
 * 
 * @param list 
 * @param size 
 * @param search 
 * @return short 
 */
short binarySearch(short list[], short size, short search){
    short middle, first = 0, last =  size - 1, count = 0;
    bool found = false;

    while(!found && first <= last){
        middle = (first + last) / 2;
        if(search == list[middle])
            found = true;
        else if(search < list[middle])
            last = middle - 1;
        else
            first = middle + 1;

        count++;
    }
    return count;
}