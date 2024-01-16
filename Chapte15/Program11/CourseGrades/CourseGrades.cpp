#include "CourseGrades.h"
#include <iomanip>
#include <iostream>


std::string CourseGrades::assignmentTypes[4] = {"Lab Activity", "Pass/Fail Exam", "Essay", "Final Exam"};
CourseGrades::CourseGrades(LabActivity &lab, PassFailExam &pfExam, Essay &essay, FinalExam &final){
    for(int index = 0 ; index < 4 ; index++)
        grades[index] = nullptr;

    setLab(lab);
    setPassFailExam(pfExam);
    setEssay(essay);
    setFinalExam(final);
}

void CourseGrades::setLab(LabActivity &lab){
    grades[0]= new LabActivity(lab);
}
void CourseGrades::setPassFailExam(PassFailExam &pfExam){
    grades[1] = new PassFailExam(pfExam);
}
void CourseGrades::setEssay(Essay &essay){
    grades[2] = new Essay(essay);
}
void CourseGrades::setFinalExam(FinalExam &final){
    grades[3] = new FinalExam(final);
}


void CourseGrades::report()const{
    std::cout << "\nAssignment Type\tScore\tGrade";

    for(short index = 0; index < 4; index++){
        std::cout << "\n" << std::setw(15) << std::left << assignmentTypes[index] << "\t" << grades[index]->getScore() << "\t" << grades[index]->getLetterGrade();
    }

}

CourseGrades::~CourseGrades(){
    for(int index = 0; index < 4; index++){
        delete grades[index];
        grades[index] = nullptr;
    }
}