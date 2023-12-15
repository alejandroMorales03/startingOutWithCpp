#include "/Users/alejandromorales/projects/Chapter13/Inventory/Inventory.h"
#include <iostream>
#include <iomanip>

int main(){
    Inventory item(0103, 500, 12.49);
    int quant;

    cout << setprecision(2) << fixed;

    cout << "\nHow many: ";
    cin >> quant;

    cout << "\nSUBTOTAL: $ " << setw(8) << item.getCost() * quant * 1.30;
    cout << "\nTAX:      $ " << setw(8) << item.getCost() * quant * 1.30 * 0.06;
    cout << "\nTOTAL     $ " << setw(8) << item.getCost() * quant * 1.30 * 1.06 << "\n\n"; 
    return 0;
}