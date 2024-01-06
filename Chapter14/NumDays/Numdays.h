#ifndef NUMDAYS_H
#define NUMDAYS_H


class Numdays{
    private:
        float workDays;
        float workedHours;

        void converter();

    public:
        Numdays(float hours);
        Numdays();

        float getWorkedHours()const;
        float getWorkDays()const;

        void setWorkedHours(float hours);

        Numdays operator+(const Numdays &right);
        Numdays operator-(const Numdays &right);
        Numdays operator++();
        Numdays operator--();
        Numdays operator++(int);
        Numdays operator--(int);

      
};

#endif