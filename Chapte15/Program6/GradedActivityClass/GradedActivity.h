#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

#include <iostream>

class GradedActivity{
    private:
        double AGrade, BGrade, CGrade, DGrade;
        static double const MIN_SCORE;
        double MAX_SCORE;
        double grade;
        char letterGrade;
        char passOrFailGrade;

        bool validRange(double studentGrade);

    protected:
        void determineLetterGrade();
        void determinePassOrFail(double minPass = 60);
        void setGrade(double studentGrade);


    public:
        GradedActivity(double studentGrade = 0, double minPassScore = 60, double upBound = 100, double Alimit = 90, double Blimit = 80, double Climit = 70, double Dlimit = 60);


        double getGrade()const;
        char getLetterGrade()const;
        char passOrFail() const;

        virtual ~GradedActivity(){std::cout << "\nDestroying GA" << grade;}


};

#endif