#include "Month.h"

using namespace std;

string Month::monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", 
                              "September", "October", "November", "December"};

Month::Month(){
    numMonth = 1;
    month = "January";
}

Month::Month(string monthName){
    month = monthName;
    bool found = false;

    short index;
    for(index = 0; index < NUM_MONTHS && !found; index++){
        if(month == monthNames[index]){
            found = true;
        }
    }

    if(!found){
        cout << "\nINVALID MONTH DETECTED\n\n";
        exit(0);
    }

    numMonth = index;
}

Month::Month(int num){
    numMonth = num > 0 && num < 13? num : num < 1? 12 : 1;
    month = monthNames[numMonth - 1];
}

int Month::getNumMonth()const{
    return numMonth;
}
string Month::getLitMonth()const{
    return month;
}

void Month::setMonth(int num){
    *this = Month(num);

}
void Month::setMonth(string monthName){
    *this = Month(monthName);
}

Month Month::operator++(){
    numMonth++;
    this->setMonth(numMonth);
    return *this;
}
Month Month::operator--(){
    numMonth--;
    this->setMonth(numMonth);
    return *this;
}
Month Month::operator++(int){
    Month temp(*this);
    numMonth++;
    this->setMonth(numMonth);
    return temp;
}
Month Month::operator--(int){
    Month temp(*this);
    numMonth--;
    this->setMonth(numMonth);
    return temp;
}

ostream &operator << (ostream &os, const Month& monthObj){
    os << monthObj.getLitMonth();
    return os;
}
istream &operator >> (istream &is, Month& monthObj){
    cout << "Enter numeric form of the month: ";
    int userInput;
    cin >> userInput;
    monthObj.setMonth(userInput);
    return is;
}
