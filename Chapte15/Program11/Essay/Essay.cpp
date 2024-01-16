#include "Essay.h"
#include <iostream>

Essay::Essay(double pointsEarned, double maximum ):
    GradedAssignment(pointsEarned, maximum){
        setScore();
        setLetterGrade();

}

void Essay::setScore(){
    checkInput();
    score = getPoints() / getMaxPoints() * 100;
}

void Essay::checkInput(){
    if(getMaxPoints() < getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: LABACTIVITY ESSAY");
    if(getPoints() < getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: LABACTIVITY ESSAY");
}

Essay::~Essay(){}