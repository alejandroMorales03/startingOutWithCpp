#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount{
    private :
        double balance;
        double annualIntRate;

    protected:
        double monthlyServCharges;
        int numberDepMonth;
        int numberWithMonth;

    public:
        BankAccount(double startBalanace, double yearIntRate);

        void setBalance(double startBalanace);
        void setAnnIntRate(double interet);

        double getBalance()const;
        double getAnnIntRate()const;
        double getMonthlyServiceCharges()const;

        virtual void deposit(double amountToDeposit);
        virtual void withdraw(double amountToWithdraw);
        virtual void caclInt();
        virtual void monthylyProc();

        virtual ~BankAccount();

};

#endif