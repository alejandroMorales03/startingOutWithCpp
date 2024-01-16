#ifndef COURSEGRADES_H
#define COURSEGRADES_H

#include "/Users/alejandromorales/projects/Chapte15/Program11/GradedAssignment/GradedAssignment.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/LabActivity/LabActivity.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/PassFailExam/PassFailExam.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/FinalExam/FinalExam.h"
#include "/Users/alejandromorales/projects/Chapte15/Program11/Essay/Essay.h"
#include <iostream>

class CourseGrades{
    private:
        static std::string assignmentTypes[4];
        GradedAssignment *grades[4];
    public:
        CourseGrades(LabActivity &lab, PassFailExam &pfExam, Essay &essay, FinalExam &final);

        void setLab(LabActivity &lab);
        void setPassFailExam(PassFailExam &pfExam);
        void setEssay(Essay &essay);
        void setFinalExam(FinalExam &final);

        void report()const;

        ~CourseGrades();
};

#endif