#include <iostream>
#include <iomanip>
using namespace std;

enum BUDGET {HOUSING = 500, UTIL = 150, HOUSE_EXP = 65, TRANSP = 50,
             FOOD = 250, MED = 30, INS = 100, ENTER = 150, CLOTH = 75, 
             MISC = 50, TOTAL = 1420};

struct Expenses{
    float housing;
    float utilit;
    float household_exp;
    float transp;
    float food;
    float med;
    float insurance;
    float enter;
    float cloth;
    float misc;
    float total;
};

bool validateUserInput(float, float, float);
void populate(Expenses&);
void report(Expenses&);

int main(){
    cout << setprecision(2) << fixed;
    Expenses student;
    populate(student);
    report(student);
    cout << "\n";
    return 0;
}


bool validateUserInput(float test, float min, float max){
    if(test >= min && test <= max)
        return false;
    cout << "\nINVALID ENTRY. VALUE MUST BE POSITIVE\n\n";
    return true;
}
void populate(Expenses& exp){
    cout << "\nEnter amount spent this month in the following categories: \n\n";
    exp.total = 0;

    do{
        cout << "* HOUSING: $: ";
        cin >> exp.housing;
    }while(validateUserInput(exp.housing, 0, exp.housing));
    exp.total += exp.housing;

    do{
        cout << "* UTILITIES: $: ";
        cin >> exp.utilit;
    }while(validateUserInput(exp.utilit, 0, exp.utilit));
    exp.total += exp.utilit;

    do{
        cout << "* HOUSEHOLD EXP: $: ";
        cin >> exp.household_exp;
    }while(validateUserInput(exp.household_exp, 0, exp.household_exp));
    exp.total += exp.household_exp;

    do{
        cout << "* TRANSPORTATION: $: ";
        cin >> exp.transp;
    }while(validateUserInput(exp.transp, 0, exp.transp));
    exp.total += exp.transp;

     do{
        cout << "* FOOD: $: ";
        cin >> exp.food;
    }while(validateUserInput(exp.food, 0, exp.food));
    exp.total += exp.food;

    do{
        cout << "* MEDICAL: $: ";
        cin >> exp.med;
    }while(validateUserInput(exp.med, 0, exp.med));
    exp.total += exp.med;

    do{
        cout << "* INSURANCE: $: ";
        cin >> exp.insurance;
    }while(validateUserInput(exp.insurance, 0, exp.insurance));
    exp.total += exp.insurance;

    do{
        cout << "* ENTERTAINMENT: $: ";
        cin >> exp.enter;
    }while(validateUserInput(exp.enter, 0, exp.enter));
    exp.total += exp.enter;

    do{
        cout << "* CLOTHING: $: ";
        cin >> exp.cloth;
    }while(validateUserInput(exp.cloth, 0, exp.cloth));
    exp.total += exp.cloth;

    do{
        cout << "* MISCELLANEOUS: $: ";
        cin >> exp.cloth;
    }while(validateUserInput(exp.misc, 0, exp.misc));
    exp.total += exp.misc;    
}
 void report(Expenses& exp){
        cout << "\n* * * EXPENSE REPORT ([+] = savings and [-] = debt)\n";
        cout << "\n* HOUSING:        $ " << setw(9) << HOUSING - exp.housing;
        cout << "\n* UTILITIES:      $ " << setw(9) << UTIL - exp.utilit;
        cout << "\n* HOUSEHOLD EXP:  $ " << setw(9) << HOUSE_EXP - exp.household_exp;
        cout << "\n* TRANSPORTATION: $ " << setw(9) << TRANSP - exp.transp;
        cout << "\n* FOOD:           $ " << setw(9) << FOOD - exp.food;
        cout << "\n* MEDICAL:        $ " << setw(9) << MED - exp.med;
        cout << "\n* INSURANCE:      $ " << setw(9) << INS - exp.insurance;
        cout << "\n* ENTERTAINMENT:  $ " << setw(9) << ENTER - exp.enter;
        cout << "\n* CLOTHING:       $ " << setw(9) << CLOTH - exp.cloth;
        cout << "\n* MISCELLANEOUS:  $ " << setw(9) << MISC - exp.misc;
    }