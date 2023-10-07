#include <iostream>

using namespace std;

const float PRIV_EXP_MILE = 0.27, PARKING_ALLW_DAY = 6.0, TAXI_ALLW_DAY = 10.0, HOTEL_ALLW_NIGHT = 90,
            BF_DAY = 9, LC_DAY = 12, DR_DAY = 16;
float ALLOWABLE_MEAL_EXP = 0;


/**
 * @param float,float,float
 * @return True/False Depending on whether "checkValue" is valid or not
 * Description: Checks checkValue against a max and min value to make sure checkValue is in range.
 * An error message is displayed if checkValue is out of range.
*/
bool inputValidation(float checkValue, float minValue, float maxValue){
    bool valid = false;
    if(checkValue >= minValue && checkValue <= maxValue)
        valid = true;
    else
        cout << "\nINVALID INPUT\n";
    
    return valid;
}
void getDays(short &days){
    
    do{
        cout << "\nEnter days spent in the trip: ";
        cin >> days;
    }while(!inputValidation(days, 1, days));
    cin.ignore();
}
bool validFormat(string line){
    bool length,hour, minute, second, formatting;
    
    if(line.length() == 8) 
        length = true;
    else   
        length = false;
    if(stoi(line.substr(0, 2)) >= 0 && stoi(line.substr(0, 2)) <= 23) 
        hour = true;
    else
        hour = false;
    if(stoi(line.substr(3, 2)) >= 0 && stoi(line.substr(3, 2)) <= 59) 
        minute = true;
    else
        minute = false;
    if(stoi(line.substr(6, 2)) >= 0 && stoi(line.substr(6, 2)) <= 59) 
        second = true;
    else
        second = false;
    if((line.at(2) == ':' && line.at(5) == ':'))
        formatting = true;
    else
        formatting = false;
    
    if(length && hour && minute && second && formatting)
        return true;

    cout << "\nINVALID FORMATTING\n";
    return false;
}
short getDepTime(){
    string depTime;
    do{
       cout << "\nEnter the departure time in the format HH:MM:SS (i.e 23:59:59): ";
       getline(cin, depTime);
    }while(!validFormat(depTime));
    return (stoi(depTime.substr(0, 2)));
}
short getArrTime(){
    string depTime;
    do{
       cout << "\nEnter the arrival time in the format HH:MM:SS (i.e 23:59:59): ";
       getline(cin, depTime);
    }while(!validFormat(depTime));
    return (stoi(depTime.substr(0, 2)));
}
float getAirfareExp(){
    float airfare;
    do{
        cout << "\nEnter airfare expenses: ";
        cin >> airfare;
    }while(!inputValidation(airfare, 0, airfare));
    return airfare;
}
float carRentalExp(){
    float car_exp, miles = 0;
    short private_car;
    do{
        cout << "\nEnter car rental expenses: ";
        cin >> car_exp;
    }while(!inputValidation(car_exp, 0, car_exp));

    do{
        cout << "\nDid you use a private vehicle: \n\n1. No\n2. Yes\n\nSelection: ";
        cin >> private_car;
    }while(!inputValidation(private_car - 1, 0, 1));

    if(private_car - 1)
        do{
            cout << "\nEnter miles driven: ";
            cin >> miles;
        }while(!inputValidation(miles, 0, miles));
    
    return car_exp + miles * PRIV_EXP_MILE;

}
float getParkingExp(){
    float parking;
    do{
        cout << "\nEnter parking expenses: ";
        cin >> parking;
    }while(!inputValidation(parking, 0, parking));
    
    return parking;

}
float getTaxiExp(){
    float taxi;
    do{
        cout << "\nEnter taxi expenses: ";
        cin >> taxi;
    }while(!inputValidation(taxi, 0, taxi));
    
    return taxi;

}
float getSeminarExp(){
    float conf;
    do{
        cout << "\nEnter seminar / conference expenses: ";
        cin >> conf;
    }while(!inputValidation(conf, 0, conf));
    return conf;
}
float getHotelExp(){
    float hotel;
    do{
        cout << "\nEnter hotel expenses: ";
        cin >> hotel;
    }while(!inputValidation(hotel, 0, hotel));
    return hotel;
}
float getMealExp(short dep, short arr, short days){
    short bfast, lunch, dinner;
    bfast = lunch = dinner = days;
    float mealExp;
    if(dep > 7)
        bfast--;
        if(dep > 12)
            lunch--;
            if(dep > 18)
                dinner--;

    if(arr < 7)
        bfast--;
        if(arr < 13)
            lunch--;
            if(dep < 19)
                dinner--;

    do{
        cout << "\nEnter meal expenses: ";
        cin >> mealExp;
    }while(!inputValidation(mealExp, 0, mealExp));
    ALLOWABLE_MEAL_EXP = bfast * BF_DAY + lunch * LC_DAY + dinner * DR_DAY;
    return mealExp;
}

int main(){
    short days;
    getDays(days);
    short nights = days - 1;
    short depTime = getDepTime(),
          arrTime = getArrTime();

    float airfare = getAirfareExp(),
          carExp = carRentalExp(),
          parkingExp = getParkingExp(),
          taxi_exp = getTaxiExp(),
          sem_exp = getSeminarExp(),
          hotel_exp = getHotelExp(),
          meal_exp = getMealExp(depTime, arrTime, days);

    float allowable = airfare + days * (PARKING_ALLW_DAY + TAXI_ALLW_DAY) + (HOTEL_ALLW_NIGHT * nights) + ALLOWABLE_MEAL_EXP,
          expenses = airfare + carExp + parkingExp + taxi_exp + sem_exp + hotel_exp + meal_exp;

    cout << "\nAllowable Expenses: $ " << allowable;
    cout << "\nExpenses:           $ " << expenses;
    if(expenses > allowable)
        cout << "\nRequired Reinbursement: " << expenses - allowable;
    else if(allowable > expenses)
        cout << "\nSaved Amount:     $ " << allowable - expenses;

    cout << "\n\n";

    return 0;
}