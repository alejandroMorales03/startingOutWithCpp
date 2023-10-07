#include <iostream>
using namespace std;

bool inputValidation(float, float, float);
float profit(short, float, float, float, float);

int main(){
    short numShares;
    float priceShareSale, comPaidSale, pricePurchaseSale, comPaidPurchase, profitVar = 0;
    char choice;

    do{
        do{
            cout << "\nEnter the number of shares: ";
            cin >> numShares;
            cout << "Enter the sales' price per share: ";
            cin >> priceShareSale;
            cout << "Enter the sale comission paid: ";
            cin >> comPaidSale;
            cout << "Enter the purchase price per share: ";
            cin >> pricePurchaseSale;
            cout << "Enter the purchase comission paid: ";
            cin >> comPaidPurchase;
        }while(!(inputValidation(numShares, 0, numShares) && inputValidation(priceShareSale, 0, priceShareSale) && inputValidation(comPaidSale, 0, comPaidSale)
                && inputValidation(pricePurchaseSale, 0, pricePurchaseSale) && inputValidation(comPaidPurchase, 0, comPaidPurchase)));
        cout << "\nEnter Q to quit. Anything else to continue entering values for other shares: ";
        cin.ignore();
        choice = getchar();
        profitVar += profit(numShares, priceShareSale, comPaidSale, pricePurchaseSale, comPaidPurchase);
    }while(tolower(choice) != 'q');

    if(profitVar < 0)
        cout << "\nTotal Loss: " << -1 * profitVar;
    else   
        cout << "\nTotal Profit: " << profitVar; 
    cout << "\n\n";

    
    return 0;

}

/**
 * @param float,float,float
 * @return True/False Depending on whether "checkValue" is valid or not
 * Description: Checks checkValue against a max and min value to make sure checkValue is in range.
 * An error message is displayed if checkValue is out of range.
*/

bool inputValidation(float checkValue, float minValue, float maxValue){
    bool valid = false;
    if(checkValue >= minValue && checkValue <= maxValue)
        valid = true;
    else
        cout << "\nINVALID INPUT\n* All data must be positive.\n";
    return valid;
}

/**
 * @param shares, shareSaelesPrice, salesComission, sharePurchPrice, purchComission
 * @return The profit or the loss
 * @brief calculates the profit or loss
*/

float profit(short shares, float shareSalePrice, float saleComission, float sharePurchPrice, float purchComission){
    return ((shares * shareSalePrice) - saleComission) - ((shares * sharePurchPrice) + purchComission);
}