#include <iostream>

using namespace std;
int main(){
    short counter = 0;
    do{
        if((counter + 1) % 2 == 0)
            cout << "\n";
        cout << counter << "\t" << static_cast<char>(counter) << "\t";
        counter++;
    }while(counter <= 127);
    cout << "\n\n";
    return 0;


    
}