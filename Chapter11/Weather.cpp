#include <iostream>
#include <cmath>

using namespace std;

enum TempLimits{MINIMUM = -100, MAXIMUM = 140};
enum MONTHS{JAN, FEB, MARCH, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
struct WeatherStats
{
    float totalRainfall;
    float highTemp;
    float lowTemp;
    float avgTemp;
};

void populateStats(WeatherStats[], const string[]);
bool validateData(float, float, float);
float getAverageRainfall(WeatherStats[], float&);
float getAverageTemp(WeatherStats[]);
void findLimits(WeatherStats[], const string[]); 
int main(){
    const string MONTHS[] = {"Jan", "Feb", "March", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
    WeatherStats yearStats[12];
    populateStats(yearStats, MONTHS);

    float totalRain = 0;
    float aver_rain = getAverageRainfall(yearStats, totalRain);
    float avr_temp = getAverageTemp(yearStats);

    cout << "\nAverage Monthly Rain: " << aver_rain;
    cout << "\nAverage Monthly Temp: " << avr_temp;
    findLimits(yearStats, MONTHS);
    cout << "\n\n";

    return 0;
}

void populateStats(WeatherStats Stats[], const string months[]){
    for(short index = 0; index < 12; index++){
        cout << "\nFor " << months[index] << " enter: \n\n";
        do{
            cout << "Total Monthly Rainfall: ";
            cin >> Stats[index].totalRainfall;
        }while(validateData(Stats[index].totalRainfall, 0, Stats[index].totalRainfall));

        do{
            cout << "Highest Temperature: ";
            cin >> Stats[index].highTemp;
        }while(validateData(Stats[index].highTemp, MINIMUM, MAXIMUM));

        do{
            cout << "Lowest Temperature: ";
            cin >> Stats[index].lowTemp;
        }while(validateData(Stats[index].lowTemp, MINIMUM, MAXIMUM));

        if(Stats[index].lowTemp > Stats[index].highTemp){
            float temp = Stats[index].lowTemp;
            Stats[index].lowTemp = Stats[index].highTemp;
            Stats[index].highTemp = temp;
        }


        Stats[index].avgTemp = (Stats[index].lowTemp + Stats[index].highTemp) / 2;
    }
}

bool validateData(float test, float min, float max){
    if(test >= min && test <= max)
        return false;
    cout << "\nINVALID INPUT: VALID RANGE [" << min << "-" << -max << "]\n\n";
    return true;

}

float getAverageRainfall(WeatherStats Monthly_Stats[], float& total){
    for(short index = 0; index < 12; index++)
        total += Monthly_Stats[index].totalRainfall;
    
    cout << "\nTotal Yearly Rainfall: " << total;
    return total/12;
}

float getAverageTemp(WeatherStats Monthly_Stats[]){
    float average;
    for(short index = 0; index < 12; index++)
        average += Monthly_Stats[index].avgTemp;
    average /= 12;
    return average;
}

void findLimits(WeatherStats Monthly_Stats[], const string Months[]){

    float max = Monthly_Stats[JAN].highTemp, minim = Monthly_Stats[JAN].lowTemp;
    short max_i = JAN, min_i = JAN;

    for(MONTHS index = FEB; index <12; index = static_cast<MONTHS>(index + 1)){
        if(Monthly_Stats[index].highTemp > max){
            max_i = index;
        }
        if(Monthly_Stats[index].lowTemp < minim){
            min_i = index;
        }
    }

    cout << "\nHighest Temperature: " << Monthly_Stats[max_i].highTemp << "F, " << Months[max_i];
    cout << "\nLowest Temperature: " << Monthly_Stats[min_i].lowTemp << "F, " << Months[min_i];

}