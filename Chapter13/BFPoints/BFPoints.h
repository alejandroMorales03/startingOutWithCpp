#ifndef BFPOINTS_H
#define BFPOINTS_H

class BFPoints{
    private:
        enum BF_POINTS{ETHYL_ALC_F = -173, ETHYL_ALC_B = 172, OXY_F = -362, OXY_B = -306, WAT_F = 32, WAT_B = 212};
        float temp;

    public:
        BFPoints();
        BFPoints(float temp_u);

        void setTemp(float temp_u);
        float getTemp()const;

        bool isEthylFreezing()const;
        bool isEthylBoining()const;

        bool isOxyFreezing()const;
        bool isOxyBoiling()const;

        bool isWatFreezing()const;
        bool isWatBoiling()const;

};

#endif