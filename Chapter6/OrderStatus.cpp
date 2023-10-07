#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

bool inputValidation(float, float, float);

short getOrder();
short getStock();
bool specialCharges();
void OrderStatus(short, short, bool = false, float = 10, float = 0.10);

int main(){
    cout << setprecision(2) << fixed;
    short ordered = getOrder(),
          stock = getStock();
    OrderStatus(ordered, stock, specialCharges());


    return 0;
}

/**
 * @param float,float,float
 * @return True/False Depending on whether "checkValue" is valid or not
 * @brief Checks checkValue against a max and min value to make sure checkValue is in range.
 * An error message is displayed if checkValue is out of range.
*/
bool inputValidation(float checkValue, float minValue, float maxValue){
    bool valid = false;
    if(checkValue >= minValue && checkValue <= maxValue)
        valid = true;
    else
        cout << "\nINVALID INPUT\n* All data entered must be positive.\n";
    return valid;
}


/**
 * @param none
 * @return void
 * @brief Gets order from user and perfoms input validation
*/

short getOrder(){
    short order;
    do{
        cout << "\nHow many spools would you like to order: ";
        cin >> order;
    }while(!inputValidation(order, 0, order));
    if(order == 0){
        cout << "\nThere is no order then. Good bye\n\n";
        exit(0);
    }
    return order;
}

/**
 * @param none
 * @return available stock
 * @brief Generates a random number wich is the available stock
 */

short getStock(){
    srand(time(0));
    return (rand() % (1000 - 0 + 1) + 0);
}

/**
 * @param none
 * @return true or false
 * @brief Randomly determines if there is extra charges
*/
bool specialCharges(){
    srand(time(0));
    return (rand() & (1 - 0 + 1) + 0);
}

void OrderStatus(short ord, short stk, bool extr, float norm_c, float ext_rat){
    short ready;
    float handling;
    if(stk  > ord){
        cout << "\nReady to ship:                          " << setw(10) << right  << ord;
        ready = ord;
    }
    else{
        cout << "\nReady to ship:                          " << setw(10) << stk;
        cout << "\nBack Order:                             " << setw(10) << ord - stk;
        ready = stk;
    }

    cout << "\nSubtotal:                             $ " << setw(10) << ready * 100;
    cout << "\nTotal Handling and Shhipping Charges: $ ";
    if(ext_rat){
        cout << setw(10) << ready * (norm_c + ext_rat);
        handling = ready * (norm_c + ext_rat);
    }
    else{
        cout << setw(10) << ready * norm_c;
        handling = ready * (norm_c + ext_rat);
    }

    cout << "\nTotal                                 $ " << setw(10) << handling + ready * 100 << "\n\n";


    


}
