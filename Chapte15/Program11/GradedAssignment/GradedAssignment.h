#ifndef GRADEDASSIGNMENT_H
#define GRADEDASSIGNMENT_H

class GradedAssignment{
    private:
        enum LETTERGRADEMIN{A = 90, B = 80, C = 70, D = 60};

        static double min;
        double points;
        double max;
        double minPassingScore;
        char letterGrade;

    protected:
        double score;

        virtual void setScore() = 0;
        virtual void checkInput() = 0;
        void setLetterGrade();


    public:
        GradedAssignment(double pointsEarned = 0, double maximum = 100, double minNeeded = 60);

        void setMax(double maximum);
        void setNeeded(double minNeeded);
        void setEarned(double pointsEarned);

        double getMinPoints()const;
        double getMaxPoints()const;
        double getMinPassingScore()const;
        double getPoints()const;
        double getScore()const;
        char getLetterGrade()const;

        virtual ~GradedAssignment();


};
#endif