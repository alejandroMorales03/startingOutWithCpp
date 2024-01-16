#ifndef CHECKINGSACCOUNT_H
#define CHECKINGSACCOUNT_H

#include "/Users/alejandromorales/projects/Chapte15/Program14/BankAccountClass/BankAccount.h"

class CheckingsAccount : public BankAccount{
    public:
        CheckingsAccount(double balance, double annualInRate);
        void withdraw(double amount) override;
        void monthylyProc() override;

       virtual ~CheckingsAccount(){};
};

#endif