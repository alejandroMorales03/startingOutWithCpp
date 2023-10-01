#include <iostream>

using namespace std;

int main(){
    float monthlyBudget, total_spent = 0, holder;

    do{
        cout << "\nWhat's your budget for this month: ";
        cin >> monthlyBudget;
        if(monthlyBudget < 0)
            cout << "\nINVALID INPUT! \n* Your budget cannot be neagtive\n";
        
    }while(monthlyBudget < 0);

    cout << "\nEnter amount spent (0 if done): $ ";
    while(cin >> holder && holder != 0){
        total_spent += holder;
    }
    
    if(monthlyBudget == total_spent)
        cout << "\nYou spent your budget exactly\n\n";
    else if(monthlyBudget > total_spent)
        cout << "\nYou were $ " << monthlyBudget - total_spent << " under your budget.\n\n";
    else
        cout << "\nYou were $ " << total_spent - monthlyBudget << " over your budget.\n\n";
    return 0;

        

    
}