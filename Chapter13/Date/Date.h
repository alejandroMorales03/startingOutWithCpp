#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date
{
private:
    enum MONTH_BOUNDS{LAST_MONTH = 12, FIRST_MONTH = 1};
    enum YEAR_BOUNDS{FIRST_YEAR = 1900, LAST_YEAR = 2024};
    static string MONTH_NAMES[12];
    int LAST_DAY;
    static int FIRST_DAY;
    static bool INVALID_DATA_DETECTED;
    
    int day, month, year;
    
    bool validateRange(int value, int low_bound, int high_bound);
    bool checkLeap();

public:
    Date(int month_u = 1, int day_u = 1, int year_u = 1900);
    void NumbFormat();
    void MixedFormat();
    void StringFormat();
    void notifyInvalid();

};



#endif