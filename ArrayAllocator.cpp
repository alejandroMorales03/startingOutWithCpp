#include <iostream>
#include <memory>

using namespace std;
unique_ptr<int[]> arrayAllocator(short size);

int main(){
    short size;
    
    cout << "\nEnter size of array to be allocated: ";
    cin >> size;

    if(arrayAllocator(size)){
        cout << "\nSUCCESS\n\n";
    }
    else
        cout << "\nFAILURE\n\n";
    return 0;
    
}

/**
 * @brief Dynamically allocates an array of size ints and returns the address
 * 
 * @param size 
 * @return unique_ptr<int[]> 
 */
unique_ptr<int[]> arrayAllocator(short size){
    unique_ptr<int[]>array(new int[size]);
    return array;
}