#ifndef PASSFAILEXAM_H
#define PASSFAILEXAM_H

#include "/Users/alejandromorales/projects/Chapte15/Program11/GradedAssignment/GradedAssignment.h"
class PassFailExam : public GradedAssignment{
    private:
        char passFailGrade;

    protected:
        virtual void setScore() final;
        virtual void checkInput() final;

          
    public:
        PassFailExam(double pointsEarned = 0);
        ~PassFailExam();

}; 

#endif