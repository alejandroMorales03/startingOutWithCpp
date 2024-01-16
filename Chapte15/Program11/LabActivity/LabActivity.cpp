#include "LabActivity.h"
#include <iostream>

LabActivity::LabActivity(double pointsEarned, double maximum) : 
    GradedAssignment(pointsEarned, maximum){
        setScore();
        setLetterGrade();
}

void LabActivity::setScore(){
    checkInput();
    score = getPoints() / getMaxPoints() * 100;
}

void LabActivity::checkInput(){
    if(getMaxPoints() <= getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: LABACTIVITY OBJECT");
    if(getPoints() < getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: LABACTIVITY OBJECT");
}

LabActivity::~LabActivity(){};