#ifndef PAYROLL_H
#define PAYROLL_H

class Payroll{
    private:
        float hourlyPayRate;
        float hours_worked;
        static const float MAX_HOUR;

        bool checkBounds(float &check, float low, float high,  bool pay = false, bool hours = false);

    public:
        Payroll();
        Payroll(float hours, float perHour);
        void setHours(float& hours);
        void setPay(float perHour);
        float getGross();



};

#endif