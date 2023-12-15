#ifndef POPULATION_H
#define POPULATION_H

class population{
    private:
        int sample_pop;
        int deaths;
        int births;


    public:
        population(int pop = 0, int births_arg= 0, int deaths_arg = 0);
        void setPopulation(int pop);
        void setBirths(int births_arg);
        void setDeaths(int deaths);

        float getDeathR()const;
        float getBirthR()const;

};
#endif