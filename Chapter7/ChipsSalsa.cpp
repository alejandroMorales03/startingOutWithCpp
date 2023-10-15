#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool inputVal(float, float, float);
void Populator(short[], string[], short = 5);
bool report(string[], short[], short = 5);

int main(){
    string salsas[] = {"mild", "medium", "sweet", "hot", "zesty"};
    short jars[5];

    Populator(jars, salsas);
    if(report(salsas, jars))
        cout << "\nReport has been saved...\n\n";
    else
        cout << "\nThe report could not be saved...\n\n";

        return 0;

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

/**
 * @brief 
 * 
 * @param sold 
 * @param types 
 * @param size 
 */
void Populator(short sold[], string types[], short size){
    cout << "\nEnter number of jars sold: \n\n";
    for(short index = 0 ; index < size; index++){
        do{
            cout << types[index] << ": ";
            cin >> sold[index];
            if(!inputVal(sold[index], 0, sold[index]))
                cout << "\nERROR: INVALID INPUT. MUST BE POSITIVE\n\n";
        }while(!inputVal(sold[index], 0, sold[index]));
    }
}
/**
 * @brief 
 * 
 * @param types 
 * @param amounts 
 * @return true 
 * @return false 
 */
bool report(string types[], short amounts[], short size){
    ofstream report("/Users/alejandromorales/Desktop/Projects/Chapter7/report.txt");
    cout << "\nAttempting to crete report...\n";

    if(!report.fail()){
        short running_total = 0, lowest = amounts[0], highest = amounts[0], h_index = 0 , l_index = 0;
        for(short index = 0; index < size; index++){
            report << types[index] << " " << amounts[index] << "\n";
            running_total += amounts[index];

            if(amounts[index] > highest){
                highest = amounts[index];
                h_index = index;
            }
            else if(amounts[index] < lowest){
                lowest  = amounts[index];
                l_index = index;
            }
        }
        report << "\nTotal Jars Sold: " << running_total;
        report << "\nHighest Selling: " << types[h_index];
        report << "\nLowest Selling:  " << types[l_index];
        report.close();
        return true;
    }
    else
        return false;
}