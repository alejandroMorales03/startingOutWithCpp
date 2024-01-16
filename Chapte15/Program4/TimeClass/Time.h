#ifndef TIME_H
#define TIME_H

#include <string>
class Time{
    private:
        enum LIMITS{MAX_MINUTE_SEC = 59, MAX_HOUR = 24, MIN = 0};
        int hour;
        int minute;
        int second;
        std::string meridian;

        void changeMeridian();
        std::string formatTime();
        void setHour(int hour_u);

    public:
        Time(int hour_u = 12, int min_u = 0, int second_u = 0, std::string meridian_u = "AM");
        virtual ~Time(){};

        std::string getTime();

        
    




};

#endif