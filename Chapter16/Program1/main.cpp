#include "/Users/alejandromorales/projects/Chapter16/Program1/DateObject/Date.h"
#include <iostream>

using namespace std;

int main(){

    Date testDefaultDate; // Testing default values;
    cout << testDefaultDate.getDate();

    try{
        Date testUserDate(9, 31, -2000);
        cout << testUserDate.getDate();
    }catch(Date::InvalidYearException){
        cout << "\nINVALID YEAR EXCEPT CAUGHT\n";
    }catch(Date::InvalidDayException){
        cout << "\nINVALID DAY EXCEPT CAUGHT\n";
    }catch(Date::InvalidMonthException){
        cout << "\nINVALID MONTH EXCEPT CAUGHT\n";
    }

    return 0;
}