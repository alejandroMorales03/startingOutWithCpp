#include <iostream>
#include "/Users/alejandromorales/projects/Chapte15/Program11/Essay/Essay.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/FinalExam/FinalExam.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/LabActivity/LabActivity.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/PassFailExam/PassFailExam.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/CourseGrades/CourseGrades.h"

using namespace std;

int main(){

    LabActivity mylab(1, 80);
    PassFailExam myPfexam(70);
    Essay myEssay(45, 60);
    FinalExam myFinal(40, 50);

    CourseGrades myCourse(mylab, myPfexam, myEssay, myFinal);
    myCourse.report();
    std::cout << "\n\n";


    return 0;
}