#include <iostream>

using namespace std;

bool verifyDateInput(string);
string dateFormatter(string);

int main() {
    string date;
    cout << "Enter a date in the format (mm/dd/yyyy): ";
    getline(cin, date);

    if (verifyDateInput(date)) {
        cout << dateFormatter(date) << "\n\n";
    } else {
        cout << "Invalid Date" << "\n\n";
    }
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
string dateFormatter(string date){
    string formatted = "";
    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    formatted += months[atoi(date.substr(0, 2).c_str()) - 1] + " " + date.substr(3, 2) + ", " + date.substr(6, 4);
    return formatted;
}