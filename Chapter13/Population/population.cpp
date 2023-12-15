#include "population.h"

#include <iostream>
using namespace std;

population::population(int pop, int births_arg, int deaths_arg){
    sample_pop = pop < 0? 0 : pop;
    births = births_arg <= sample_pop && births_arg >= 0? births_arg : births_arg > sample_pop? sample_pop : 0;
    deaths = deaths_arg <= sample_pop && deaths_arg >= 0? deaths_arg : deaths_arg > sample_pop? sample_pop : 0;
}

void population::setPopulation(int pop){
    sample_pop = pop < 0? 0 : sample_pop;
}
void population::setBirths(int births_arg){
    births = births_arg <= sample_pop && births_arg >= 0? births_arg : births_arg > sample_pop? sample_pop : 0;

}
void population::setDeaths(int deaths_arg){
    deaths = deaths_arg <= sample_pop && deaths_arg >= 0? deaths_arg : deaths_arg > sample_pop? sample_pop : 0;
}
float population::getBirthR()const{
    return sample_pop > 0? static_cast<float>(births)/sample_pop : 0;
}
float population::getDeathR()const{
    return sample_pop > 0? static_cast<float>(deaths)/sample_pop : 0;
}


 
  
