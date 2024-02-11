#ifndef TIME
#define TIME

#include <iostream>
#include <string>
#include <iomanip>

class Time{
    private:
        const int MAX_HOUR;
        const int MAX_MIN_SEC;
        const int MIN;

        int hour;
        int minute;
        int second;
        std::string timeSetting;


    public:
        Time(int userHour = 0, int userMinute = 0, int userSec = 0, std::string timeOfDay = "");

        int getHour()const;
        int getMinute()const;
        int getSecond()const;
        std::string getTimeSetting()const;

        class InvalidTimeSetting{
            public: 
                std::string excp_setting;
                int excp_hour;
                
                InvalidTimeSetting(int hour, std::string setting) : excp_setting(setting), excp_hour(hour){}
        };

        class BadHour{
            public:
                int excp_hour;
                BadHour(int userHour) : excp_hour(userHour){}

               
        };

        class BadMinute{
            public:
                int excp_min;
                BadMinute(int userMinute) : excp_min(userMinute){}
        };

        class BadSecond{
            public:
                int excp_second;
                BadSecond(int userSeconds) : excp_second(userSeconds){};
        };

        virtual std::string getTime() const = 0;

        virtual ~Time();
};

#endif