#include "GradedActivity.h"
#include <iostream>

double const GradedActivity::MIN_SCORE = 0;
GradedActivity::GradedActivity(double studentGrade, double minPassScore, double upBound, double Alimit, double Blimit, double Climit, double Dlimit): grade(0){
    MAX_SCORE = upBound;
    AGrade = Alimit / MAX_SCORE * 100;
    BGrade = Blimit / MAX_SCORE * 100;
    CGrade = Climit / MAX_SCORE * 100;
    DGrade = Dlimit / MAX_SCORE * 100;

    if(AGrade < BGrade || BGrade < CGrade || CGrade < DGrade)
       throw std::runtime_error("INVALID LETTER GRADE LIMITS DETECTED");

    if(MAX_SCORE <= MIN_SCORE)
        throw std::runtime_error("Maximum score cannot be greater than or equal to the minimum score");
    if(validRange(studentGrade))
        setGrade(studentGrade);

    determinePassOrFail(minPassScore);
    determineLetterGrade();
}

void GradedActivity::setGrade(double studentGrade){
    grade = studentGrade/MAX_SCORE * 100;
}

double GradedActivity::getGrade()const{
    return grade;
}

bool GradedActivity::validRange(double studentGrade){
    if(studentGrade <= MAX_SCORE && studentGrade >= 0)
        return true;
    else    
        throw std::runtime_error("INVALID SCORE DETECTED");
}

void GradedActivity::determinePassOrFail(double minPass){
    passOrFailGrade = grade > minPass / MAX_SCORE * 100? 'P' : 'F';
}

char GradedActivity::passOrFail()const{
    return passOrFailGrade;
}

void GradedActivity::determineLetterGrade(){
    if(grade >= AGrade) letterGrade = 'A';
    else if(grade >= BGrade) letterGrade = 'B';
    else if(grade >= CGrade) letterGrade = 'C';
    else if(grade >= DGrade) letterGrade = 'D';
    else letterGrade = 'F';

}

char GradedActivity::getLetterGrade()const{
    return letterGrade;
}