#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "/Users/alejandromorales/projects/Chapte15/Program1/ProductionWorkerClass/ProductionWorker.h"
class TeamLeader : public ProductionWorker{
    private:
        double monthlyBonus;
        double yearlyTraining;
        double trainingCompleted;

    public:
        TeamLeader(std::string empName = "", int empNumber = 0, int hireMonth = 0, int hireDay = 1, int hireYear = 0, int empShift = 1, double pay = 0, double bonus = 0, double training = 0, double attended = 0);

        void setBonus(double bonus = 0);
        void setReqTraining(double reqTraining = 0);
        void setCompTraining(double comTraining = 0);

        double getBonus()const;
        double getReqTraining()const;
        double getCompTraining()const;
        double getRemainingTraining()const;

        ~TeamLeader(){};
        

};

#endif