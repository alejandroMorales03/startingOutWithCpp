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

    for(short index = 0; index < SIZE && !found; index++){
        if(search == list[index])
            found = true;
    }

    if(found)
        cout << "\nThe number is valid\n\n";
    else    
        cout << "\nThe number is invalid\n\n";
    
    return 0;
}