#ifndef ESSAY_H
#define ESSAY_H

#include "/Users/alejandromorales/projects/Chapte15/Program11/GradedAssignment/GradedAssignment.h"

class Essay : public GradedAssignment{
    protected:
        virtual void setScore();
        virtual void checkInput();

    public:
        Essay(double pointsEarned = 0, double maximum = 100);

        ~Essay();
    

};

#endif