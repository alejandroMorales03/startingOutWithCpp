#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car{
    private:
        string make;
        int yearModel;
        float speed;

    public:
        Car(int yearMode_u, string make_u);
        string getMake()const;
        int getYearModel()const;
        float getSpeed()const;
        void accelerate();
        void brake();



};

#endif