#include <iostream>
#include <iomanip>
using namespace std;

bool verifyDateInput(string arg);
void printCheck(string, string, float);


int main(){
    string date;
    do{
        cout << "\nEnter a date: (mm/dd/yy): ";
        getline(cin, date);
    }while(!verifyDateInput(date));
    
    float amount;
    do{
        cout << "\nEnter the amount to write the check for: ";
        cin >> amount;
        if(amount < 0.01 || amount > 10000)
            cout << "\nINVALID AMOUNT\n";
    }while(amount < 0.01 || amount > 10000);
    std::cin.ignore();

    string name;
    cout << "\nEnter the person the check is going to: ";
    getline(cin, name);


    name.insert(0, "Pay to the Order of: ");
    printCheck(date, name, amount);

    return 0;
}

bool verifyDateInput(string arg) {
    if (arg.length() != 10) {
        cout << "Invalid input length." << "\n";
        return false;
    }

    if(arg.at(2) != '/' || arg.at(5) != '/'){
        cout << "Invalid Formatting" << "\n";
    }

    short months_lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (atoi(arg.substr(0, 2).c_str()) > 12 || atoi(arg.substr(0, 2).c_str()) < 1) {
        cout << "Invalid month." << "\n";
        return false;
    }

    int year = atoi(arg.substr(6, 4).c_str());

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        months_lengths[1] = 29; // Leap year
    }

    if (atoi(arg.substr(3, 2).c_str()) > months_lengths[atoi(arg.substr(0, 2).c_str()) - 1] ||
        atoi(arg.substr(3, 2).c_str()) < 1) {
        cout << "Invalid day for the given month." << "\n";
        return false;
    }

    return true;
}

void printCheck(string date, string name, float amount){
    cout << "\n\n" << setw((name + "\t\t\t\t\t\t\t\t").length()) << "Date: " << date;
    cout << "\n" << setw((name + "\t\t\t").length()) << "$" << setprecision(2) << fixed << amount;
    cout << "\n" << name << "\n\n";
}