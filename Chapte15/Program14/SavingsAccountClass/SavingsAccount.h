#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>

#include "/Users/alejandromorales/projects/Chapte15/Program14/BankAccountClass/BankAccount.h"

class SavingsAccount : public BankAccount{
    private:
        bool status;
    public:
        SavingsAccount(double balance, double annualRate);

        void withdraw(double amount) override;
        void deposit(double amount) override;
        void monthylyProc() override;

        ~SavingsAccount(){};
};

#endif