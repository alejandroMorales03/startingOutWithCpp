#include <iostream>
#include <iomanip>
using namespace std;

void Populator(string[], float[], short = 12);
bool inputVal(float, float, float);
void Sorter(string[], float[]);
int main(){
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
    float rainfall[12];

    Populator(months, rainfall);
    Sorter(months, rainfall);

    cout << "\nList of months from most to least rainy\n\n";
    for(string month_holder : months)
        cout << month_holder << "\n";
    cout << "\n";

    return 0;
}

/**
 * @brief Uses an array to populate the rainfall array using each month's name as reference
 * 
 * @param months 
 * @param rainfall_amounts 
 * @param size 
 */
void Populator(string months[], float rainfall_amounts[], short size){
    cout << "\nEnter rain amounts for the following months: \n";
    for(short index = 0; index < size; index++){
        do{
            cout << months[index] << ": ";
            cin >> rainfall_amounts[index];
            if(!inputVal(rainfall_amounts[index], 0, rainfall_amounts[index]))
                cout << "\nERROR: INVALID INPUT. MUST BE POSITIVE\n\n";
        }while(!inputVal(rainfall_amounts[index], 0, rainfall_amounts[index]));
    }
}

/**
 * @brief Performs input validation
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

void Sorter(string months[], float rainfall[]){
    bool swap;
    float temp;
    string temp_m;
    do{
        swap = false;
        for(short index = 0; index < 11; index++){
            if(rainfall[index] < rainfall[index + 1]){
                temp = rainfall[index];
                rainfall[index] = rainfall[index + 1];
                rainfall[index + 1] = temp;
                swap = true;
                temp_m = months[index];
                months[index] = months[index + 1];
                months[index + 1] = temp_m;
            }
        }

    }while(swap);

}