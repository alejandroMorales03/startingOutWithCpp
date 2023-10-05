#include <iostream>
using namespace std;
const string DIVISIONS[] ={"Northeast","Southeast","Northwest", "Southwest"};

bool inputValidation(float, float, float);
float getSales(string);
void findHighest();

int main(){
    cout << "\n";
    findHighest();
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
    if(checkValue >= minValue && checkValue >= maxValue)
        valid = true;
    else
        cout << "\nINVALID INPUT\n* All data entered must be positive.\n\n";
    
    return valid;
}

/**
 * @param string 
 * @return Returns a float corresponding to the sales for a given division
 * Descripion: Performs data retrieval and input validation
*/
float getSales(string division){
    float sales;
    do{
        cout << "Enter sales for " << division << " division: ";
        cin >> sales;
    }while(!inputValidation(sales, 0, sales));
    return sales;
}

/**
 * @param string 
 * @return Nothing
 * Descripion: Displays the highest selling division and the highest amount
*/
void findHighest(){
    float sales[] = {getSales(DIVISIONS[0]),getSales(DIVISIONS[1]),getSales(DIVISIONS[2]),getSales(DIVISIONS[3])};
    float max = sales[0];
    short max_i = 0;
    
    for(short i = 0; i < 4; i++){
        if(sales[i] > max){
            max = sales[i];
            max_i = i;
        }
    }
    cout << "\nThe highest selling division was " << DIVISIONS[max_i] << " with $ " << max << "\n";
}