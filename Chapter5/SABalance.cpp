#include <iostream>

using namespace std;

int main(){
    float balance, monthIntRate, holder, total_int_earned;
    short numMonths, total_deposits = 0, total_withdrawals = 0;
    bool closedAcc = false;

    do{
        cout << "\nEnter starting balance: ";
        cin >> balance;
        if(balance < 0){
            cout << "\nINVALID INPUT!\n* Error: Negative Starting Balance\n";
            continue;
        }

        cout << "\nEnter annual interest rate: ";
        cin >> monthIntRate;
        if(monthIntRate <0){
            cout << "\nINVALID INPUT!\n* Error: Negative Interest Rate (%)\n";
            continue;
        }
        monthIntRate /= 1200;

        cout << "\nEnter number of months that have passed since opening the account: ";
        cin >> numMonths;
        if(numMonths < 1){
            cout << "\nINVALID INPUT! \n* Months must be at least 1\n";
            continue;
        }

    }while(balance < 0 || monthIntRate < 0 || numMonths < 1);

    for(short c_month = 1; c_month <= numMonths; c_month++){
        do{
            cout << "\nEnter amount deposited in month " << c_month << ": ";
            cin >> holder;
            if(holder < 0)
                cout << "\nINVALID INPUT! \n* Negative deposits are invalid\n";
        }while(holder < 0);
        if(holder > 0)
            total_deposits++;
        balance += holder;

        do{
            cout << "\nEnter total amount withdrawn in month " << c_month << ": ";
            cin >> holder;
            if(holder < 0)
                cout << "\nINVALID INPUT! \n* Negative withdrawns are not allowed\n";
        }while(holder < 0);
        if(holder > 0)
            total_withdrawals++;
        balance -= holder;

        if(balance < 0){
            cout << "\nAccount has been closed\n\n";
            closedAcc = true;
            break;
        }

        total_int_earned += (balance *  monthIntRate);
        balance *= (1 + monthIntRate);
    }

    if(!closedAcc){
        cout << "\nEnding Balance: $         " << balance;
        cout << "\nTotal Amount of Deposits: " << total_deposits;
        cout << "\nTotal Withdrawals:        " << total_withdrawals;
        cout << "\nTotal Interest Earned:    " << total_int_earned << "\n\n";
    }
    return 0;

}