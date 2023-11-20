#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Customer{
    string name;
    string address;
    string cty_ste_zip;
    string phone_number;
    float balance;
    string last_payment;
};
bool validatePhoneNumber(string);
bool verifyDateInput(string);
bool validateUserInput(float, float, float);

void deleteRecord(fstream&, Customer&);
void createRecord(fstream&, Customer&);
void displayRecord(fstream&, Customer&);
void modifyRecord(fstream&, Customer&);
void printDB(fstream&, Customer&);

int main(){
    cout << setprecision(2) << fixed;
    short menu_choice;

    fstream record;
    Customer customer_container;
    do{
        cout << "\n* * * Menu * * * \n";
        cout << "\n1. Enter New Records";
        cout << "\n2. Display a Customer's Record";
        cout << "\n3. Delete a Customer's Record";
        cout << "\n4. Modify a Customer's Record";
        cout << "\n5. Display all Records";
        cout << "\n6. Exit";
        cout << "\n\nSelection: ";
        cin >> menu_choice;
        cin.ignore();

        switch(menu_choice){
            case 1:{
                createRecord(record, customer_container);
                break;
            }
            case 2:{
                displayRecord(record, customer_container);
                break;
            }
            case 3:{
                deleteRecord(record, customer_container);
                break;
            }
            case 4:{
                modifyRecord(record, customer_container);
                break;
            }
            case 5:{
                printDB(record, customer_container);
                break;
            }

            case 6:{
                cout << "\nSHUTTING DOWN...\n";
                break;
            }
            default:{
                cout << "\nINVALID CHOICE\n";
                break;
            }
        }
    }while(menu_choice != 6);

}

bool verifyDateInput(string arg) {
    if (arg.length() != 10) {
        cout << "\nInvalid input length." << "\n\n";
        return false;
    }

    if(arg.at(2) != '/' || arg.at(5) != '/'){
        cout << "\nInvalid Formatting" << "\n\n";
    }

    short months_lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (atoi(arg.substr(0, 2).c_str()) > 12 || atoi(arg.substr(0, 2).c_str()) < 1) {
        cout << "\nInvalid month." << "\n\n";
        return false;
    }

    int year = atoi(arg.substr(6, 4).c_str());

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        months_lengths[1] = 29; // Leap year
    }

    if (atoi(arg.substr(3, 2).c_str()) > months_lengths[atoi(arg.substr(0, 2).c_str()) - 1] ||
        atoi(arg.substr(3, 2).c_str()) < 1) {
        cout << "Invalid day for the given month." << "\n\n";
        return false;
    }
    

    return true;
}
bool validatePhoneNumber(string phone_number){
    bool isValid = true;
    
    if(phone_number.length() != 14)
        isValid = false;

    if(phone_number.at(0) != '(' || phone_number.at(4) != ')' || 
       phone_number.at(5) != ' ' || phone_number.at(9) != '-')
        isValid = false;

    for(short index = 0; index < phone_number.length() && !isValid; index++){
        if(index != 0 && index != 4 && index != 5 && index != 9){
            if(!isdigit(phone_number.at(index)))
                isValid = false;
        }
    }

    if(!isValid)
        cout << "\nINVALID PHONE NUMBER\n\n";

    return isValid;
    
}
bool validateUserInput(float test, float min, float max){
    if(test <= max && test >= min)
        return false;
    cout << "\n[ERROR] INVALID ENTRY\n";
    return true;
}

void createRecord(fstream& cus_rec, Customer& customer){
    cus_rec.open("cus_records.txt", ios::out|ios::app);

    if(!cus_rec.is_open() || cus_rec.fail()){
        cout << "\n* ERROR OPENING FILE\n";
    }
    else{
        cout << "\nEnter customer's name: ";
        getline(cin, customer.name);

        cout << "Enter customer's address: ";
        getline(cin, customer.address);

        cout << "Enter customer's city, state, and zip: ";
        getline(cin, customer.cty_ste_zip);

        do{
            cout << "Enter customer's phone number: ";
            getline(cin, customer.phone_number);
        }while(!validatePhoneNumber(customer.phone_number));

        do{
            cout << "Enter customer's date of last payment: ";
            getline(cin, customer.last_payment);
        }while(!verifyDateInput(customer.last_payment));

        do{
            cout << "Enter customer's balance: $ ";
            cin >> customer.balance;
            cin.ignore();
        }while(validateUserInput(customer.balance, 0, customer.balance));


        cus_rec.write(reinterpret_cast<char *>(&customer), sizeof(customer));

        cus_rec.clear();
        cus_rec.close();
    }

}
void displayRecord(fstream& cus_rec, Customer& customer){
    cus_rec.open("cus_records.txt", ios::in|ios::binary);

    if(!cus_rec.good())
        cout << "\nFILE ERROR\n";
    else{
        string name;
        cout << "\nEnter customer's name: ";
        getline(cin, name);

        bool found = false;

        while(!found && cus_rec.read(reinterpret_cast<char *>(&customer), sizeof(customer))){
            if(customer.name.find(name) != string::npos)
                found = true;
        }
              
        if(!found)
            cout << "\nNO RECORD FOUND\n";
        else{
            cout << "\n* NAME: " << customer.name;
            cout << "\n* ADDRESS: " << customer.address + " " +  customer.cty_ste_zip;
            cout << "\n* PHONE NUMBER: " << customer.phone_number;
            cout << "\n* BALANCE: $ " << customer.balance;
            cout << "\n* DATA OF LAST PAYMENT: " << customer.last_payment;
            cout << "\n";
        }
        cus_rec.clear();
        cus_rec.close();

    }

}

void deleteRecord(fstream& cus_rec, Customer& customer){
    cus_rec.open("cus_records.txt", ios::out|ios::in|ios::binary);

    if(!cus_rec.good())
        cout << "\nFILE ERROR\n";
    else{
        string name;
        cout << "\nEnter customer's name: ";
        getline(cin, name);

        bool found;
        vector<Customer> customers_list;

        while(cus_rec.read(reinterpret_cast<char *>(&customer), sizeof(customer))){
            if(customer.name != name)
                customers_list.push_back(customer);
            else
                found = true;
        }
        if(!found)
            cout << "\nNO RECORD FOUND\n";
        else{
            if(remove("cus_records.txt") == 0){
                fstream upd_rec("cus_records.txt", ios::app|ios::binary);
                for (short index = 0; index < customers_list.size(); index++){
                    upd_rec.write(reinterpret_cast<char *>(&customers_list[index]), sizeof(customers_list[index]));
                }

                upd_rec.clear();
                upd_rec.close();
                cout << "\nFILE SUCCESSFULLY UPDATED\n";
            }
            else{
                cout << "\nFILE COULD NOT BE UPDATED\n";
            }
        }
        cus_rec.clear();
        cus_rec.close();
    }
}
void modifyRecord(fstream& cus_rec, Customer& customer){
    cus_rec.open("cus_records.txt", ios::in|ios::out|ios::ate|ios::binary);

    string record_to_modify;
    cout << "\nEnter customer's name for the record to be modified: ";
    getline(cin, record_to_modify);

    bool found = false;

    cus_rec.seekg(0, ios::beg);
    while(!found && cus_rec.read(reinterpret_cast<char *>(&customer), sizeof(customer))){
        if(record_to_modify == customer.name)
            found = true;
    }


    if(found){
        cout << "\nEnter customer's name: ";
        getline(cin, customer.name);

        cout << "Enter customer's address: ";
        getline(cin, customer.address);

        cout << "Enter customer's city, state, and zip: ";
        getline(cin, customer.cty_ste_zip);

        do{
            cout << "Enter customer's phone number: ";
            getline(cin, customer.phone_number);
        }while(!validatePhoneNumber(customer.phone_number));

        do{
            cout << "Enter customer's date of last payment: ";
            getline(cin, customer.last_payment);
        }while(!verifyDateInput(customer.last_payment));

        do{
            cout << "Enter customer's balance: $ ";
            cin >> customer.balance;
            cin.ignore();
        }while(validateUserInput(customer.balance, 0, customer.balance));

        cus_rec.seekp(-static_cast<long>(sizeof(customer)), ios::cur);
        cus_rec.write(reinterpret_cast<char *>(&customer), sizeof(customer));
    }
    else    
        cout << "\nRECORD NOT FOUND\n";

    cus_rec.clear();
    cus_rec.close();
}

void printDB(fstream& cus_rec, Customer& customer){
    cus_rec.open("cus_records.txt", ios::in|ios::binary);

    if(!cus_rec.good())
        cout << "\nFILE ERROR\n";
    else{
        while(cus_rec.read(reinterpret_cast<char*>(&customer), sizeof(customer))){
            cout << "\n* NAME: " << customer.name;
            cout << "\n* ADDRESS: " << customer.address + " " +  customer.cty_ste_zip;
            cout << "\n* PHONE NUMBER: " << customer.phone_number;
            cout << "\n* BALANCE: $ " << customer.balance;
            cout << "\n* DATA OF LAST PAYMENT: " << customer.last_payment;
            cout << "\n";
        }

        cus_rec.clear();
        cus_rec.close();

        cout << "\nNO MORE RECORDS TO DISPLAY\n";

    }
}
