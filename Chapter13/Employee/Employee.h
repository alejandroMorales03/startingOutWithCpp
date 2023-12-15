#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee{
    private:
        long id_number;
        string name;
        string department;
        string position;
    
    public:
        Employee(long id_u, string name_u, string dept_u, string pos_u);
        Employee(long id_u, string name_u);
        Employee();

        void setID(long id_u){id_number = id_u > 0? id_u : 0;}
        void setName(string name_u){name = name_u;}
        void setDepartment(string dept_u){department = dept_u;}
        void setPosition(string pos_u){position = pos_u;}

        long getID()const{return id_number;}
        string getName()const{return name;}
        string getDepartment()const{return department;}
        string getPosition()const{return position;}
};

#endif