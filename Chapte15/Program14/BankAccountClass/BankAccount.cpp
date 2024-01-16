#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(double startBalanace, double yearIntRate){
    numberDepMonth = 0;
    numberWithMonth = 0;
    monthlyServCharges = 0;
    setBalance(startBalanace);
    setAnnIntRate(yearIntRate);
}

void BankAccount::setBalance(double startBalanace){
    if(startBalanace <= 0)
        throw std::runtime_error("ERROR TYPE| NEGATIVE STARTING INBALANCE OR $ 0.00 STARTING BALANCE");
    balance = startBalanace;
}

void BankAccount::setAnnIntRate(double interest){
    if(interest < 0)
        throw std::runtime_error("ERROR TYPE| NEGATIVE ANNUAL INTEREST RATE");
    annualIntRate = interest;
}


double BankAccount::getBalance()const{
    return balance;
}
double BankAccount::getAnnIntRate()const{
    return annualIntRate;
}
double BankAccount::getMonthlyServiceCharges()const{
    return monthlyServCharges;
}


void BankAccount::deposit(double amountToDeposit){
    if(amountToDeposit < 0)
        throw std::runtime_error("ERROR TYPE| NEGATIVE DEPOSIT AMOUNT");

    balance += amountToDeposit;
    numberDepMonth++;

}
void BankAccount::withdraw(double amountToWithdraw){
    if(amountToWithdraw < 0)
        throw std::runtime_error("ERROR TYPE| NEGATIVE WITHDRAW AMOUNT");

    if(balance - amountToWithdraw < 0)
        throw std::runtime_error("ERROR TYPE| WITHDRAW OPERATION LEADS TO NEGATIVE BALANCE");

    balance -= amountToWithdraw;
    numberWithMonth++;

}
void BankAccount::caclInt(){
    balance += (annualIntRate / 12.00) * balance;
}
void BankAccount::monthylyProc(){
    balance -= monthlyServCharges;
    if(balance < 0){
        throw std::runtime_error("\nERROR TYPE| THIS ACCOUNT HAS BEEN CLOSED DUE TO INSUFFICIENT FUNDS\n");
    }

    numberDepMonth = 0;
    numberWithMonth = 0;
    monthlyServCharges = 0;

}

BankAccount::~BankAccount(){}