#include <iostream>
using namespace std;

int main(){
    string names[] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri",
                      "Jhonson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob",
                      "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    
    short size = 20;
    string MinValue;
    short minIndex;
    for(short startScan = 0; startScan < size - 1; startScan++){
        MinValue = names[startScan];
        minIndex = startScan;

        for(short index = startScan + 1; index < size; index++){
            if(names[index] < MinValue){
                MinValue = names[index];
                minIndex = index;
            }
        }
        
        names[minIndex] = names[startScan];
        names[startScan] = MinValue;
    }
    for(string holder : names)
        cout << holder << "\n";
    cout << "\n";
    return 0;
}

