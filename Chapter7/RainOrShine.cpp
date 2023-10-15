#include <iostream>
#include <fstream>
using namespace std;

const short MONTHS = 3, DAYS = 30;
void ReadFile(ifstream&, char[][DAYS]);
void ReportTotals(char[][DAYS]);
short findExtreme(short[MONTHS]);


int main(){
    ifstream inputFile("/Users/alejandromorales/Desktop/Projects/Chapter7/RainOrShine.txt");
    if(!inputFile.fail()){

        char wheatherData[3][DAYS];
        ReadFile(inputFile, wheatherData);
        ReportTotals(wheatherData);
    }
    else{
        cout << "\nERROR OPENING FILE!...\n\n";
    }
    return 0;
}

/**
 * @brief Reads a file into an array
 * 
 * @param fileObj 
 * @param storage 
 */
void ReadFile(ifstream& fileObj, char storage[][DAYS]){
    for(short month = 0; month < MONTHS; month++){
        for(short days = 0; days < DAYS; days++){
            storage[month][days] = fileObj.get();
        }
    }
    fileObj.close();
}

/**
 * @brief Creates and updates a running total for each weather type
 * 
 * @param storage 
 */
void ReportTotals(char storage[][DAYS]){
    const char SUNNY = 'S', CLOUDY = 'C', RAINY = 'R';
    short totalsSeason[3] = {0,0,0};
    short rainyTotals[3] = {0,0,0};
    string months[3] = {"June", "July", "August"};

    for(short month = 0; month < MONTHS; month++){
        for(short day = 0; day < DAYS; day++){
            switch(storage[month][day]){
                case SUNNY: 
                    totalsSeason[0]++;
                    break;
                case CLOUDY:
                    totalsSeason[1]++;
                    break;
                case RAINY:
                    totalsSeason[2]++;
                    rainyTotals[month]++;
                    break;
            }
        }
    }


    cout << "\nThere wwere a total of " << totalsSeason[0] << " sunny days";
    cout << "\nThere wwere a total of " << totalsSeason[1] << " cloudy days";
    cout << "\nThere wwere a total of " << totalsSeason[2] << " rainy days";
    cout << "\nThe most rainy month was " << months[findExtreme(rainyTotals)] << "\n\n"; 
}


/**
 * @brief finds the maximum value in an array
 * 
 * @param list 
 * @return short 
 */
short findExtreme(short list[MONTHS]){
    short max = list[0];
    short m_index = 0;
    
    for(short index = 1; index < MONTHS; index++){
        if(list[index] > max){
            max = list[index];
            m_index = index;
        }
    }

    return m_index;

}



