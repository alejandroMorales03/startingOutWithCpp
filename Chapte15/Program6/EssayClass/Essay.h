#ifndef ESSAY_H
#define ESSAY_H
#include <iostream>
#include "/Users/alejandromorales/projects/Chapte15/Program6/GradedActivityClass/GradedActivity.h"
class Essay : public GradedActivity{
    private:
        enum CATEG_LIMITS{Grammar = 30, Spelling = 20, Length = 20, Content = 30};
        double grammar, spelling, length, content;
    
    public:
        Essay(double grammarScore = 0, double spellingScore = 0, double lengthScore = 0, double contentScore = 0);
        virtual ~Essay(){std::cout << "\nDestroying ES" << getGrade();}


};


#endif