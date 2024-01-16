#include "Teamleader.h"
#include <iostream>

TeamLeader::TeamLeader(std::string empName, int empNumber, int hireMonth, int hireDay, int hireYear, int empShift, double pay, double bonus, double training, double attended) :
    ProductionWorker(empName, empNumber, hireMonth, hireDay, hireYear, empShift, pay){
        setBonus(bonus);
        setReqTraining(training);
        setCompTraining(attended);

    }

void TeamLeader::setBonus(double bonus){
    monthlyBonus = bonus < 0? 0 : bonus;
}

void TeamLeader::setReqTraining(double training){
    yearlyTraining = training < 0? 0 : training;
}

void TeamLeader::setCompTraining(double attended){
    trainingCompleted = attended < 0? 0 : attended;  
}

double TeamLeader::getBonus()const{
    return monthlyBonus;
}

double TeamLeader::getCompTraining()const{
    return trainingCompleted;
}

double TeamLeader::getReqTraining()const{
    return yearlyTraining;
}

double TeamLeader::getRemainingTraining()const{
    double remaining = getReqTraining() - getCompTraining();
    if(remaining <= 0){
        std::cout << "ALL TRAINING HAS BEEN COMPLETED\n";
        return 0;
    }
    return remaining;
}