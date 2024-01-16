#include "PassFailExam.h"
#include <iostream>

PassFailExam::PassFailExam(double pointsEarned) :
    GradedAssignment(pointsEarned, 100, 70){
        setScore();
        setLetterGrade();
}

void PassFailExam::setScore(){
        checkInput();
        score = getPoints();
    if(score >= getMinPassingScore())
        passFailGrade = 'A';
    else
        passFailGrade = 'F';
}

void PassFailExam::checkInput(){
    if(getMaxPoints() <= getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: PASSFAILEXAM OBJECT");
    if(getPoints() < getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: PASSFAILEXAM OBJECT");
}

PassFailExam::~PassFailExam(){}