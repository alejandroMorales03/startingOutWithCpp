#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Invt{
    string description;
    short qty_hand;
    float wholesale;
    float retail;
    string date;

};

int main(){

    fstream file("record.txt", ios::in|ios::binary);
    Invt container;

    float total_ws = 0, total_rs = 0, total_hand = 0;

    if(!file.is_open() || file.fail())
        cout << "\nFILE OPENING ERROR\n";
    else{
        while((file.read(reinterpret_cast<char *>(&container), sizeof(container)))){
            total_rs += container.retail;
            total_ws += container.wholesale;
            total_hand += container.qty_hand;
        }
        
        file.clear();
        file.close();
    }

    cout << "\nTotal Wholesale Value: $ " << setw(10) << total_ws;
    cout << "\nTotal Retail value:    $ " << setw(10 )<< total_rs;
    cout << "\nTotal Quantity On Hand:  " << setw(10) << total_hand;
    cout << "\n\n";

    return 0;
}