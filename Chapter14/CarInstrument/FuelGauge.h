#ifndef FUELGUAGE_H
#define FUELGUAGE_H

class FuelGauge{
    private:
        static const int MAX_GALLONS = 15;
        float gallonsInTank;

        void tankStatusNotice();

    public:
        FuelGauge(float gallons = 0);
        float getGallons()const;
        float getTankCapacity() const;


        FuelGauge operator++();
        FuelGauge operator++(int);

        FuelGauge operator--();
        FuelGauge operator--(int);

        
};

#endif