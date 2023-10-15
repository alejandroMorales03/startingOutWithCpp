#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

void writeToFile(ofstream&);
void readFromFile(ifstream&, vector<float>&);
short findExtandTotal(vector<float>, float&, short = 0);

int main(){
    cout << setprecision(2) << fixed;
    ofstream writer("/Users/alejandromorales/Desktop/Projects/Chapter7/numbers.txt");

    if(!writer.fail()){
        writeToFile(writer);
        writer.close();
    }
    else{
        cout << "\nERROR. FILE COULD NOT BE OPEN...\n";
    }

    ifstream reader("/Users/alejandromorales/Desktop/Projects/Chapter7/numbers.txt");
    if(!reader.fail()){
        vector<float> readData(0);
        readFromFile(reader, readData);
        reader.close();
        float total = 0;

        cout << "\nTotal numbers in file:  " << setw(6) << readData.size();
        cout << "\nBiggest Number:         " << setw(6) << findExtandTotal(readData, total, 1);
        cout << "\nSmallest Number:        " << setw(6) << findExtandTotal(readData, total, 0);
        cout << "\nAverage:                " << setw(6) << total/readData.size() << "\n\n";
    }
    else
        cout << "\nERROR. FILE COULD NOT BE OPEN...\n\n";


    return 0;
}

/**
 * @brief Writes a random number of random numbers to a file in different lines each
 * 
 * @param obj 
 */
void writeToFile(ofstream& obj){
    srand(time(0));
    short max = (rand() % (100 - 1 + 1 ) +1);
    for(short count = 0; count < max; count++){
        obj << (rand() % (100 - 1 + 1) + 1);
        if(count != max - 1)
            obj << "\n";
    }
}

/**
 * @brief Reads numbers from a file into a vector
 * 
 * @param obj 
 * @param storage 
 * @return short 
 */
void readFromFile(ifstream& obj, vector<float>& storage){
    float holder;
    while(obj >> holder){
        storage.push_back(holder);
    }
    cout << storage.size();
}

/**
 * @brief Finds the lowest or highest number and keeps a running total of all numbers
 * 
 * @param numbers 
 * @param total 
 * @param minOrMax 
 * @return short 
 */
short findExtandTotal(vector<float> numbers, float& total, short minOrMax){
    if(numbers.empty())
        return 0;
    float compValue = numbers.at(0);
    for(short index = 0; index < numbers.size(); index++){
        total += numbers[index];

        if(minOrMax == 0){
            if(numbers[index] < compValue)
                compValue = numbers[index];
        }
        else if(minOrMax == 1){
            if(numbers[index] > compValue)
                compValue = numbers[index];
        }
    }
    return compValue;

}
