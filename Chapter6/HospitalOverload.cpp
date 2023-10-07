#include <iostream>


using namespace std;


bool inputValidation(float, float, float, bool = true);
bool getAdmissionType();
void inPatient();
void outPatient();

int main(){

    getAdmissionType()? outPatient() : inPatient();

    return 0;
}

/**
 * @param none
 * @return returns true if out-patient, returns false if in-patient
 * @brief Lets the user select between in-patient and out-patient
*/

bool getAdmissionType(){
    short admTyp;
    
    do{
        cout << "\nSelect admission type: \n1. In-Patient\n2. Out-Patient\n\n";
        cout << "Selection: ";
        cin >> admTyp;
    }while(!inputValidation((--admTyp), 0, 1, false));
    return admTyp;
}

/**
 * @param float,float,float
 * @return True/False Depending on whether "checkValue" is valid or not
 * @brief Checks checkValue against a max and min value to make sure checkValue is in range.
 * An error message is displayed if checkValue is out of range.
*/

bool inputValidation(float checkValue, float minValue, float maxValue, bool output){
    bool valid = false;
    if(checkValue >= minValue && checkValue <= maxValue)
        valid = true;
    else{
        cout << "\nINVALID INPUT\n";
        if(output)
            cout << "* All data entered must be positive.\n";
    }
    return valid;
}

/**
 * @param none
 * @return total charges for an out patient
 * @brief Takes expenses and adds them together.
*/

void outPatient(){
    float charges, medicine;

    do{
        cout << "\nHospital Charges: $ ";
        cin >> charges;
        cout << "Medication Charges: $ ";
        cin >> medicine;
    }while(!(inputValidation(charges, 0, charges) && inputValidation(medicine, 0, medicine)));
    cout << "\nTotal Charges: $ " << charges + medicine << "\n\n"; 
}

/**
 * @param none
 * @return total charges for an out patient
 * @brief Takes expenses and adds them together.
*/

void inPatient(){
    float charges, medicine, days, drate;

    do{
        cout << "\nHospital Charges: $ ";
        cin >> charges;
        cout << "Medication Charges: $ ";
        cin >> medicine;
        cout << "Days in Hospital: ";
        cin >> days;
        cout << "Daily Rate: $ ";
        cin >> drate;
    }while(!(inputValidation(charges, 0, charges) && inputValidation(medicine, 0, medicine)
          && inputValidation(days, 0, days) && inputValidation(drate, 0, drate)));
    cout << "\nTotal Charges: $ " << charges + medicine + days * drate << "\n\n";


}


