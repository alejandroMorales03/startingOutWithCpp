#include "mortgage.h"
#include <iostream>
#include <cmath>

using namespace std;

mortgage::mortgage(){
    loanAmount = 0;
    intRate = 0;
    loanYears = 0;
}
mortgage::mortgage(float loan, float rate, int years){
    
    loanAmount = loan < 0.01? 0 : loan;
    intRate = rate < 0? 0 : rate;
    loanYears = years < 1? 1 : years;

}

void mortgage::setLoan(float loan_u){
    loanAmount = loan_u < 0.01? 0 : loan_u;
}
void mortgage::setIntt(float int_u){
    intRate = int_u < 0? 0 : int_u;
}
void mortgage::setYears(int years_u){
    loanYears = years_u < 1? 1 : years_u;
}

float mortgage::getPayment()const{
   float answer = (loanAmount * intRate/12 * pow(( 1 + intRate/12), 12 * loanYears)) / (pow((1 + intRate/12), 12 * loanYears) - 1);
   if(std::isnan(answer))
        return 0;
    else 
        return answer;
}

float mortgage::getDifference()const{
    return (loanYears / 12.0) * getPayment();
}

