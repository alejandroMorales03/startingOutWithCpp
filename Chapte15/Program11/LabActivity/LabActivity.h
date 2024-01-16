#ifndef LABACTIVITY_H
#define LABACTIVITY_H

#include "/Users/alejandromorales/projects/Chapte15/Program11/GradedAssignment/GradedAssignment.h"

class LabActivity : public GradedAssignment{
    protected:
        virtual void setScore() final;
        virtual void checkInput() final;

    public:
        LabActivity(double pointsEarned = 0, double maximum = 100);

        virtual ~LabActivity();

};

#endif