#include <iostream>
#include "Teamleader.h"

using namespace std;


int main(){
    TeamLeader newTeamLeader("Alejandro Morales", 4703, 3, 7, 2003, 1, 18.50, 500, 100, 30);
    cout << "\n" << newTeamLeader.getName();
    cout << "\n" << newTeamLeader.getID();
    cout << "\n" << newTeamLeader.getHireDate();
    cout << "\n" << newTeamLeader.getPay();
    cout << "\n" << newTeamLeader.getBonus();
    cout << "\n" << newTeamLeader.getReqTraining();
    cout << "\n" << newTeamLeader.getCompTraining();
    cout << "\n" << newTeamLeader.getRemainingTraining() << "\n";


    newTeamLeader.modifyEmpName("Alejandro Javier");
    newTeamLeader.modifyEmpID(1000);
    newTeamLeader.modifyHireDate(0, 1, 1900);
    newTeamLeader.changePay(20);
    newTeamLeader.changeShift(2);
    newTeamLeader.setBonus(10);
    newTeamLeader.setReqTraining(80);
    newTeamLeader.setCompTraining(81);

    cout << "\n" << newTeamLeader.getName();
    cout << "\n" << newTeamLeader.getID();
    cout << "\n" << newTeamLeader.getShift();
    cout << "\n" << newTeamLeader.getHireDate();
    cout << "\n" << newTeamLeader.getPay();
    cout << "\n" << newTeamLeader.getBonus();
    cout << "\n" << newTeamLeader.getReqTraining();
    cout << "\n" << newTeamLeader.getCompTraining();
    cout << "\n" << newTeamLeader.getRemainingTraining() << "\n";

    return 0;
}