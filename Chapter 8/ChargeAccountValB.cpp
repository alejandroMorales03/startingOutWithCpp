#include <iostream>
using namespace std;

int main(){
    short SIZE = 18;
    long list[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                   8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                   1005231, 6545231, 3852085, 7576651, 7881200, 4581002};

    bool found = false;;
    long search;

    cout << "\nEnter a search number: ";
    cin >> search;

    long minValue;
    short minIndex;
    for(short startScan = 0; startScan < SIZE - 1; startScan++){
        minValue = list[startScan];
        minIndex = startScan;

        for(short index = startScan + 1; index < 1; index++){
            if(list[index] < minValue){
                minValue = list[index];
                minIndex = index;
            }
        }

        list[minIndex] = list[startScan];
        list[startScan] = minValue;
    }
    short first = 0, last = SIZE - 1, middle;
    while(!found && first <= last){
        middle = (first + last) / 2;
        if(list[middle] == search)
            found = true;
        else if(search < list[middle])
            last = middle - 1;
        else
            first = middle + 1;
    }
    if(found)
        cout << "\nThe number is valid\n\n";
    else    
        cout << "\nThe number is invalid\n\n";
    
    return 0;
}