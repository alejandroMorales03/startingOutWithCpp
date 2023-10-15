#include <iostream>
#include <iomanip>
using namespace std;

void Populator(string[], float[], short = 12);
float totalRainfall(float[], short = 12); 
short findExtreme(float[],short, short = 12);
bool inputVal(float, float, float);

int main(){
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
    float rainfall[12], total;

    Populator(months, rainfall);
    total = totalRainfall(rainfall);
    cout << setprecision(2) << fixed;
    cout << "\nTotal Rainfall:           " << setw(8) << total;
    cout << "\nAverage Monthly Rainfall: " << setw(8) << total/12;
    cout << "\nHighest Month:            " << setw(8) << months[findExtreme(rainfall, 1)];
    cout << "\nLowest Month:             " << setw(8) << months[findExtreme(rainfall, 0)] << "\n\n";


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
 * @brief Uses a loop to add every value in the rainfall array
 * 
 * @param rainfall 
 * @param size 
 * @return float 
 */

float totalRainfall(float rainfall[], short size){
    float total = 0;
    for(short index = 0; index < size; index++){
        total += rainfall[index];
    }

    return total;
}

/**
 * @brief finds the index correspondinf to the lowest or highest value
 * 
 * @param rainfall 
 * @param months 
 * @param maxOrMin 
 * @return short 
 */
short findExtreme(float rainfall[], short maxOrMin, short size){
    float compVal = rainfall[0];
    short r_index= 0;
    for(short index = 1; index < size; index++){
        if(maxOrMin == 0){
            if(rainfall[index] < compVal){
                r_index = index;
                compVal = rainfall[index];
            }
        }
        else if(maxOrMin == 1){
            if(rainfall[index] > compVal){
                r_index = index;
                compVal = rainfall[index];
            }
            
        }
    }
    return r_index;
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