#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double annualRate) : BankAccount(balance, annualRate){
    if(balance < 25)
        status = false;
    else
        status = true;
}

void SavingsAccount::withdraw(double amount){
    if(status)
        BankAccount::withdraw(amount);
    else
        throw std::runtime_error("ERROR TYPE| THIS ACCOUNT IS INACTIVE");
}

void SavingsAccount::deposit(double amount){
    if(!status && getBalance() + amount > 25)
        status = true;
    BankAccount::deposit(amount);
}

void SavingsAccount::monthylyProc(){
    if(numberWithMonth > 4)
        monthlyServCharges += numberWithMonth - 4;
    BankAccount::monthylyProc();
    if(getBalance() < 25){
        status = false;
        std::cout << "\nTHIS ACCOUNT IS NOW INACTIVE. FUNDS ARE BELOW $ 25.00\n";
    }

}