#include <iostream>
#include <iomanip>

using namespace std;

bool inputVal(float, float, float);
void Populator(long[], float[], float[], float[], short);
void Printer(long[], float[], short);
int main(){
    cout << setprecision(2) << fixed;
    long empID[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    float hours[7];
    float payRate[7], wages[7];
    Populator(empID, hours, payRate, wages, 7);
    Printer(empID, wages, 7);
    return 0;
}

/**
 * @brief Performs input validation with user-entered data
 * 
 * @param check 
 * @param min 
 * @param max 
 * @return true 
 * @return false 
 */
bool inputVal(float check, float min, float max){
    return (check >= min && check <= max);
}

/**
 * @brief Populates the given arrays with user-entered data
 * 
 * @param IDs 
 * @param hours 
 * @param rates 
 * @param pay 
 */
void Populator(long IDs[], float hours[], float rates[], float pay[], short size){
    for(short index = 0; index < size; index++){
        cout << "\nFor employee " << IDs[index] << " enter: \n\n";
        do{
            cout << "Hours worked this week: ";
            cin >> hours[index];
            if(!inputVal(hours[index], 0, hours[index]))
                cout << "\nERROR: INVALID INPUT. MUST BE POSITIVE\n\n";
        }while(!inputVal(hours[index], 0, hours[index]));
        do{
            cout << "Hourly wage: ";
            cin >> rates[index];
            if(!inputVal(rates[index], 15, rates[index]))
                cout << "\nERROR: INVALID INPUT. MUST BE GREATER THAN 15\n\n";
        }while(!inputVal(rates[index], 15, rates[index]));
        pay[index] = rates[index] * hours[index];
    }
}

/**
 * @brief Prints the contents of the ID and grosspay arrays
 * 
 * @param IDs 
 * @param grossPay 
 * @param size 
 */
void Printer(long IDs[], float grossPay[], short size){
    for(short index  = 0; index < size; index++){
        cout << "\nEmployee " << IDs[index] << ": $ " <<  setw(8) << grossPay[index];
    }
    cout << "\n\n";
}