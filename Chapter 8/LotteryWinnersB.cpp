#include <iostream>
using namespace std;

int main(){
    short SIZE = 10;
    int lucky_winners[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    int search;

    cout << "\nEnter this week's winning number: ";
    cin >> search;
    bool found = false;
    short first = 0, last = SIZE -1, middle;
    
    while(!found && first <= last){
        middle = (last + first) / 2;
        if(search == lucky_winners[middle])
            found = true;
        else if(search < lucky_winners[middle])
            last = middle - 1;
        else
            first = middle + 1;
    }

    if(found)
        cout << "\nWINNER\n\n";
    else
        cout << "\nNO WINNER\n\n";

    return 0;

}