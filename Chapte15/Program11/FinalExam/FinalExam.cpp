#include "FinalExam.h"
#include <iostream>

FinalExam::FinalExam(int rightQuestions, int totalQuestion):
    GradedAssignment(rightQuestions, totalQuestion){
        setScore();
        setLetterGrade();

}

void FinalExam::checkInput(){
    if(getMaxPoints() < getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: FINALEXAM OBJECT");
    if(getPoints() < getMinPoints())
        throw std::runtime_error("ERROR TYPE| MAX SCORE IS SMALLER THAN MIN SCORE. LOCATION: FINALEXAM OBJECT");
}

void FinalExam::setScore(){
    checkInput();
    score = getPoints() / getMaxPoints() * 100;
}

FinalExam::~FinalExam(){}