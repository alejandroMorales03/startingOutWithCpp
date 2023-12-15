#include "Inventory.h"
#include <iostream>
#include <iomanip>

int main(){
    cout << setprecision(2) << fixed;
    Inventory myInvt;
    cout << "\nItem Number: " << setw(6) << myInvt.getItemNum();
    cout << "\nQuantity :   " << setw(6) << myInvt.getQuan();
    cout << "\nCost:       $" << setw(6) << myInvt.getCost();
    cout << "\nTotal Cost: $" << setw(6) << myInvt.getTotalCost();

    myInvt.setQuantity(1000);
    myInvt.setCost(23.45);
    myInvt.setQuantity(10);
    myInvt.setItemNumber(1000);

    cout << "\n\nItem Number: " << setw(6) << myInvt.getItemNum();
    cout << "\nQuantity :   " << setw(6) << myInvt.getQuan();
    cout << "\nCost:       $" << setw(6) << myInvt.getCost();
    cout << "\nTotal Cost: $" << setw(6) << myInvt.getTotalCost() << "\n\n";
    return 0;

}