#include <iostream>

using namespace std;
int main(){

    for(short row = 1; row <= 10; row++){
        cout << "\n";
        for(short col = 1; col <= row; col++)
            cout << "+ ";
    }
    cout << "\n";
    for(short row = 1; row <= 10; row++){
        cout << "\n";
        for(short col = 10; col >= row; col--)
            cout << "+ ";
    }
    cout << "\n\n";
    return 0;
}