#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void randomString(string[], short);
void sort(string[], short);
bool biSearch(string[], string, short);

int main(){

    srand(time(0));
    short size = (rand() % (1000 - 2 + 1) + 2);
    string words[size];
    randomString(words, size);
    sort(words, size);
    for(string holder : words)
        cout << holder << "\n";

    string search;
    cout <<"\nEnter a word to search for: ";
    cin >> search;
    if(biSearch(words, search, size))
        cout << "\nFOUND\n\n";
    else
        cout << "\nNOT FOUND\n\n";
    return 0;
}

/**
 * @brief generates an array of random size of strings of random lengths
 * 
 * @param words 
 * @param size 
 */
void randomString(string words[], short size){
    short length;
    string word;
    for(short index = 0; index < size; index++){
        length = (rand() % (12 - 2 + 1) + 2);
        word = "";
        for(short letter = 0; letter < length; letter++){
            word += static_cast<char>(rand() % (90 - 65 + 1) + 65);
        }
        words[index] = word;
    }
}

/**
 * @brief Sorts the array of strings using selection sort
 * 
 * @param words 
 * @param size 
 */
void sort(string words[], short size){
    string minValue;
    short minIndex;

    for(short startScan = 0; startScan < size - 1; startScan++){
        minValue = words[startScan];
        minIndex = startScan;

        for(short index  = startScan + 1; index < size; index++){
            if(words[index] < minValue){
                minValue = words[index];
                minIndex = index;
            }
        }

        words[minIndex] = words[startScan];
        words[startScan] = minValue;
    }
}

/**
 * @brief searches for a given value using binary search
 * 
 * @param words 
 * @param search 
 * @param size 
 * @return true 
 * @return false 
 */
bool biSearch(string words[], string search, short size){
    short middle, first = 0, last = size - 1;
    bool found = false;

    while(!found && first <= last){
        middle = (first + last)/ 2;
        if(words[middle] == search)
            found = true;
        else if(search < words[middle])
            last = middle - 2;
        else
            first = middle + 1;
    }

    return found;

}
