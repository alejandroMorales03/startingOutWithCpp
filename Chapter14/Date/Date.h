#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
    private:
        static string monthNames[12];
        static int lastDayOfMonth;
        static int lastMonthOfTheYear;
        
        int day;
        int month;
        int year;

        void setLastDayOfMonth();
        bool checkLeap();

        
    public:
        Date(int dMonth = 1, int dDay = 1, int dYear = 1800);
        void setDate(int dMonth, int dDay, int dYear);
        void printDate();

        Date operator++();
        Date operator++(int);

        Date operator--();
        Date operator--(int);

        bool operator!=(const Date& anotherDate);
        bool operator<(const Date& anotherDate);

        int operator-(const Date& anotherDate);

        friend istream &operator>>(istream &stream, Date& obj);
        friend ostream &operator<<(ostream &stream, const Date& obj);

};



#endif