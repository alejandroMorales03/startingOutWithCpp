#ifndef FINALEXAM_H
#define FINALEXAM_H

#include "/Users/alejandromorales/projects/Chapte15/Program11/GradedAssignment/GradedAssignment.h"

class FinalExam : public GradedAssignment{
    protected:
        virtual void setScore() final;
        virtual void checkInput() final;
    
    public:
        FinalExam(int rightQuestions = 0, int totalQuestion = 50);
        virtual ~FinalExam();


};


#endif