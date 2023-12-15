#ifndef MORTGAGE_H
#define MORTGAGE_H

class mortgage{
    private:
        float loanAmount;
        float intRate;
        int loanYears;

            
    public:
        mortgage();
        mortgage(float loan, float rate, int years);
        void setLoan(float loan_u);
        void setIntt(float int_u);
        void setYears(int years_u);
        float getPayment() const;
        float getDifference()const;

    };



#endif