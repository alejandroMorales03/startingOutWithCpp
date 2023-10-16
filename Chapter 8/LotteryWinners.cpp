#include <iostream>
using namespace std;

int main(){
    short SIZE = 10;
    int lucky_winners[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    int search;

    cout << "\nEnter this week's winning number: ";
    cin >> search;

    bool found = false;

    for(short index = 0; index < SIZE && !found; index++){
        if(search == lucky_winners[index]){
            found = true;
        }
    }

    if(found)
        cout << "\nWINNER\n\n";
    else
        cout << "\nNO WINNER\n\n";



    return 0;
}