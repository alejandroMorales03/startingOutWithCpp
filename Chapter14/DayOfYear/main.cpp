#include "Day.h"

#include <iostream>

using namespace std;

int main(){
    int day;

    cout << "\nEnter a day of the year 1 - 365 and I will determine the date: ";
    cin >> day;

    Day myDate(day);
    myDate.print();

    Day anotherDay(31, "December");
    anotherDay.print();
    ++anotherDay;
    anotherDay.print();
    --anotherDay;
    anotherDay.print();

    myDate = anotherDay++;
    myDate.print();
    anotherDay.print();
    anotherDay = myDate--;
    myDate.print();
    anotherDay.print();




    return 0;
}