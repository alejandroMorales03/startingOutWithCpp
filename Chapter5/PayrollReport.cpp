#include <iostream>
#include <iomanip>

using namespace std;
int main(){

    short empID;
    float total_gross = 0, state_tax_total = 0, fed_total = 0, FICA_total = 0;
    float gross_holder, state_holder, fed_holder, fica_holder;

    do{
        do{
            cout << "\nEnter employee ID: ";
            cin >> empID;
            if(empID < 0)
                cout << "\nINVALID INPUT!\n* Invalid Employee ID. Error Type: Unrecognized Character (-)\n";
        }while(empID < 0);
        
        if(empID != 0){
            do{
                do{
                    cout << "\nEnter gross pay: ";
                    cin >> gross_holder; 
                    if(gross_holder < 0)
                        cout << "\nINVALID INPUT!\n* Gross pay cannot be negative\n";
                }while(gross_holder < 0);
    
                do{
                    cout << "\nEnter state tax percent deducated: (1 - 100 %): ";
                    cin >> state_holder;
                    state_holder /= 100;
                        if(state_holder < 0 || state_holder * gross_holder > gross_holder){
                            cout << "\nINVALID INPUT!\n* Deduction percentage cannot be negative";
                            cout << "\n* State tax deducated amount cannot be greater than gross pay\n";
                        }
                }while(state_holder < 0 || state_holder * gross_holder > gross_holder);

                do{
                    cout << "\nEnter federal tax percent deducated: (1 - 100 %): ";
                    cin >> fed_holder;
                    fed_holder /= 100;
                        if(fed_holder < 0 ||fed_holder * gross_holder > gross_holder){
                            cout << "\nINVALID INPUT!\n* Deduction percentage cannot be negative";
                            cout << "\n* Federal tax deducated amount cannot be greater than gross pay\n";
                        }
                }while(fed_holder < 0 ||fed_holder * gross_holder > gross_holder);

                do{
                    cout << "\nEnter withheld FICA amount: ";
                    cin >> fica_holder;
                        if(fica_holder < 0 ||fica_holder > gross_holder){
                            cout << "\nINVALID INPUT!\n* Deduction percentage cannot be negative";
                            cout << "\n* Federal tax deducated amount cannot be greater than gross pay\n";
                        }
                }while(fica_holder < 0 ||fica_holder > gross_holder);
                
                if(fed_holder * gross_holder + state_holder * gross_holder + fica_holder > gross_holder)
                    cout << "\nINVALID INPUT!\n* The summ of all deducations cannot be greater than the total gross pay\n";
            }while(fed_holder * gross_holder + state_holder * gross_holder + fica_holder > gross_holder);

            total_gross += gross_holder;
            state_tax_total += state_holder * gross_holder;
            fed_total += fed_holder * gross_holder;
            FICA_total += fica_holder;
            
        }
    }while(empID != 0);
    
    cout << "\nTotal Gross Pay:         $ " << setprecision(2) << fixed << setw(6) << total_gross;
    cout << "\nTotal State Tax:         $ " << setprecision(2) << fixed << setw(6) << state_tax_total;
    cout << "\nTotal Federal Tax:       $ " << setprecision(2) << fixed << setw(6) << fed_total;
    cout << "\nTotal FICA Withholdings: $ " << setprecision(2) << fixed << setw(6) << FICA_total;
    cout << "\nTotal Net Pay:           $ " << setprecision(2) << fixed << setw(6) << total_gross - (state_tax_total + fed_total + FICA_total) << "\n\n";
    return 0;



   
}