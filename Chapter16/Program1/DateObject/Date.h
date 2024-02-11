#ifndef DATE_H
#define DATE_H

#include <string>

class Date{
    private:
        static const std::string MONTH_NAMES[12];
        const int MIN_DAY_AND_MONTH;
        const int MAX_DAY[3];
        const int MAX_MONTH;
        const int MIN_YEAR;

        int max_day;
        int month;
        int day;
        int year;
        std::string month_name;

        bool checkRange(int max, int min, int value);
        bool checkLeap();

    public:

        class InvalidYearException{
            private: 
                int except_year;
            public:
                InvalidYearException(int year_arg);

        };
        class InvalidDayException{
            private:
                int except_day;
                int except_month;
            public:
                InvalidDayException(int day_arg, int month_arg);

        };
        class InvalidMonthException{
            private:
                int month_except;
            public:
                InvalidMonthException(int month_arg);
        };
        
        Date(int month_arg = 1, int day_arg = 1, int year_arg = 1900);

        std::string getDate()const;

    
    
};

#endif