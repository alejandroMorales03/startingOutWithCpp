#include "GradedAssignment.h"

double GradedAssignment::min = 0;

GradedAssignment::GradedAssignment( double pointsEarned, double maximum, double minNeeded){
    setMax(maximum);
    setNeeded(minNeeded);
    setEarned(pointsEarned);
}

GradedAssignment::~GradedAssignment(){}

void GradedAssignment::setMax(double maximum){
    max = maximum;
}

void GradedAssignment::setNeeded(double minNeeded){
    minPassingScore = minNeeded;
}
void GradedAssignment::setEarned(double pointsEarned){
    points = pointsEarned;
}

void GradedAssignment::setLetterGrade(){
    if(score >= A)
        letterGrade = 'A';
    else if(score >= B)
        letterGrade = 'B';
    else if(score >= C)
        letterGrade = 'C';
    else if(score >= D)
        letterGrade = 'D';
    else
        letterGrade = 'F';
}

double GradedAssignment::getMaxPoints()const{return max;}
double GradedAssignment::getMinPoints()const{return min;}
double GradedAssignment::getMinPassingScore()const{return minPassingScore;}
double GradedAssignment::getPoints()const{return points;}
double GradedAssignment::getScore()const{return score;}
char GradedAssignment::getLetterGrade()const{return letterGrade;}