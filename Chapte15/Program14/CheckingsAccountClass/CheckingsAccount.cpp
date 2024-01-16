#include "CheckingsAccount.h"
#include <iostream>

CheckingsAccount::CheckingsAccount(double balance, double annualInRate) : BankAccount(balance, annualInRate){

}

void CheckingsAccount::withdraw(double amount){
    if(getBalance() - amount < 0){
        setBalance(getBalance() - 15);
        if(getBalance() < 0)
            std::cout << "\nYOU OWE THE BANK " << abs(getBalance());
    }

        
    else
        BankAccount::withdraw(amount);
}

void CheckingsAccount::monthylyProc(){
    monthlyServCharges += 5;
    monthlyServCharges += numberWithMonth * 0.10;
    BankAccount::monthylyProc();
}