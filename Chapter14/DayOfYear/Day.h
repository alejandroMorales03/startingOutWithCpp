#ifndef DAY_H
#define DAY_H

#include <iostream>
using namespace std;

class Day{
    private:
        int day;
        static const int MAX_DAYS, MIN_DAYS;
        static string monthKeys[12];

    public:
        Day(int day);
        Day(int day, string month);
        void print();
        void print(int test);


        Day operator++();
        Day operator--();
        Day operator++(int);
        Day operator--(int);


};


#endif