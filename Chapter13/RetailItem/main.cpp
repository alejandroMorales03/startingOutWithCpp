#include "Retail.h"

#include <iostream>
#include <iomanip>

int main(){
    cout << setprecision(2) << fixed;

    Retail myItems[3] = {Retail(),Retail("Designer Jeans", 40), Retail("Shirt")};

    for(short index = 0; index < 3; index++){
        cout << setw(strlen("Designer Jeans")) << myItems[index].getDesc() <<  "\t" << myItems[index].getUnits() << "\t" << setw(2) << myItems[index].getPrice() << "\n";
    }
    cout << "\n";
    myItems[0].setDesc("Jacket");
    myItems[0].setUnits(12);
    myItems[0].setPrice(59.95);

    myItems[1].setPrice(34.95);
    myItems[2].setUnits(20);
    myItems[2].setPrice(24.95);

    for(short index = 0; index < 3; index++){
        cout << setw(strlen("Designer Jeans")) << myItems[index].getDesc() <<  "\t" << myItems[index].getUnits() << "\t" << setw(2) << myItems[index].getPrice() << "\n";
    }


    
    return 0;
}