#ifndef MONTH_H
#define MONTH_H

#include <iostream>
using namespace std;

class Month{
    private:
        static string monthNames[12];
        static const int NUM_MONTHS = 12;

        int numMonth;
        string month;
    public:

        Month();
        Month(string MonthName);
        Month(int num);

        int getNumMonth()const;
        string getLitMonth()const;

        void setMonth(int num);
        void setMonth(string monthName);

        Month operator++();
        Month operator--();

        Month operator++(int);
        Month operator--(int);

        friend ostream &operator << (ostream &os, const Month& monthObj);
        friend istream &operator >> (istream &is, Month& monthObj);




};

#endif 