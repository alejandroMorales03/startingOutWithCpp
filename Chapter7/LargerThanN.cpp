#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inspect(int[], int, int);

int main(){
    
    srand(time(0));
    int size = (rand() % (50 - 1 + 1) + 1);
    int array[size];
    int n = (rand() % (50 - 1 + 1) + 1);
    inspect(array, size, n);
    return 0;
}

void inspect(int array[], int size, int n){
    for(short index = 0; index < size; index++){
        if(array[index] > n)
            cout << array[index] << " ";
    }
    cout << "\n\n";

}