#include <iostream>
#include <iomanip>
using namespace std;

struct DrinkInfo {
    string name;
    float cost;
    short qty_available;
};

short num_options = 5;
short getBestWidth(DrinkInfo[]);
void printOptions(DrinkInfo[]);
short pickDrink(DrinkInfo[]);
bool processPurchase(DrinkInfo&);
bool validateUserInput(float, float, float);

int main() {
    cout << setprecision(2) << fixed;
    DrinkInfo vending_machine[] = {{"Cola", .75, 20},
                                    {"Root Beer", .75, 20},
                                    {"Lemon-Lime", .75, 20},
                                    {"Grape Soda", .80, 20},
                                    {"Cream Soda", .80, 20}};
    short choice = pickDrink(vending_machine);
    if(choice == 6)
        cout << "\n* * * THANK YOU * * *";
    else{
        choice--;
        if(processPurchase(vending_machine[choice]))
            printOptions(vending_machine);
        else
            cout << "\n* * * THANK YOU * * * ";
    }
    cout << "\n";    
    return 0;
}

short getBestWidth(DrinkInfo drink[]) {
    short ideal_width = 0;
    for (short index = 0; index < num_options; index++) {
        if (drink[index].name.length() > ideal_width)
            ideal_width = drink[index].name.length();
    }
    return ideal_width;
}
void printOptions(DrinkInfo machine[]) {
    short width = getBestWidth(machine);
    cout << "\n" << setw(width) << "Name" << "\tCost\t" << "Number in Machine\n\n";
    for (short index = 0; index < num_options; index++) {
        cout << (index + 1) << ". " << setw(width) << machine[index].name;
        cout << "\t" << setw(4) << machine[index].cost;
        cout << "\t\t" << setw(5) << machine[index].qty_available << "\n";
    }
    cout << "\n";
}
short pickDrink(DrinkInfo machine[]){
    short pick;
    do{
        printOptions(machine);
        cout << "6. EXIT\n";
        cout << "\nPick a drink: ";
        cin >> pick;
    }while(validateUserInput(pick, 1, 6));
    return pick;
}

bool validateUserInput(float test, float min, float max){
    if(test <= max && test >= min)
        return false;
    cout << "\n[ERROR] INVALID ENTRY\n";
    return true;
}

bool processPurchase(DrinkInfo& drink){
   
    float payment;
    do{
        do{
            cout << "\n(Press 3 to cancel purchase)\n\nEnter: $ ";
            cin >> payment;
            if(payment == 3)
                return false;
        }while(validateUserInput(payment, 0, 1));
        if(payment < drink.cost)
            cout << "\nNOT ENOUGH MONEY\n";
    }while(payment < drink.cost);
    
    drink.qty_available--;
    cout << "\nYour change: $ " << payment - drink.cost << "\n";
    return true;
}
