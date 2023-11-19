#include <iostream>
#include <vector>

using namespace std;

struct Customer{
    string name; 
    string address;
    string city_state_zip;
    string phone_number;
    double account_balance;
    string date_last_payment;
};

bool validateUserInput(float, float, float);
bool validatePhoneNumber(string);
bool verifyDateInput(string);
void phoneNumberbasedSorter(vector<Customer>&);

void addClient(vector<Customer>&);
void printDB(vector<Customer>, short = -1,bool = false);
short phoneNumberSearch(vector<Customer>, string);
void modifyClient(vector<Customer>& current_clients, short index_c);

int main(){

    static vector<Customer>client_list;

    short option;   
    do{
        do{
            cout << "\n* * * Menu * * * \n";
            cout << "\n1. Enter new customer information";
            cout << "\n2. Modify customer information: ";
            cout << "\n3. Display database";
            cout << "\n4. Exit";
            cout << "\n\nSelection: ";
            cin >> option;
        }while(validateUserInput(option, 1, 4));

        switch(option){
            case 1:{
                addClient(client_list);
                break;
            }
            case 2:{
                phoneNumberbasedSorter(client_list);
                string phone_number;

                do{
                    cin.ignore();
                    cout << "\nEnter the phone number of the client profile you would like to modify: ";
                    getline(cin, phone_number);
                }while(validatePhoneNumber(phone_number));
                
                short found_client = phoneNumberSearch(client_list, phone_number);
                printDB(client_list, found_client, true);

                short confirm;
                cout << "\nAre you sure you want to modify this profile: \n\n1. Yes\n2. No\n\nSelection: ";
                cin >> confirm;

                if(confirm == 1)
                    modifyClient(client_list, found_client);
                    

                break;

            }
            case 3:{
                printDB(client_list, -1);
                break;
            }

        }
    cout << "\n";
    }while(option != 4);
    return 0;


}

bool validateUserInput(float test, float min, float max){
    if(test <= max && test >= min)
        return false;
    cout << "\n[ERROR] INVALID ENTRY\n";
    return true;
}
void addClient(vector<Customer>& current_clients){
    Customer new_client;

    cin.ignore();
    cout << "\nEnter new client's name: ";
    getline(cin, new_client.name);

    cout << "\nEnter address: ";
    getline(cin, new_client.address);

    cout << "\nEnter city, state, zip: ";
    getline(cin, new_client.city_state_zip);

    do{
        cout << "\nEnter phone number [(000) 000-0000]: ";
        getline(cin, new_client.phone_number);
    }while(validatePhoneNumber(new_client.phone_number));

    do{
        cout << "\nEnter account balance: ";
        cin >> new_client.account_balance;
    }while(validateUserInput(new_client.account_balance, 0, new_client.account_balance));

    do{
        cin.ignore();
        cout << "\nEnter date of last payment: ";
        getline(cin, new_client.date_last_payment);
    }while(!verifyDateInput(new_client.date_last_payment));

    current_clients.push_back(new_client);

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

    return isValid;
    
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
void printDB(vector<Customer> current_clients, short single, bool search){
    cout << "\n* * * Clients * * * ";

    if(single == -1 && !search){
        for(short index = 0; index < current_clients.size(); index++){
            cout << "\n\n* Name: " << current_clients[index].name;
            cout << "\n* Address " << current_clients[index].address;
            cout << " " << current_clients[index].city_state_zip;
            cout << "\n* Phone Number: " << current_clients[index].phone_number;
            cout << "\n* Account Balance: $ " << current_clients[index].account_balance;
            cout << "\n* Date of Last Payment: " << current_clients[index].date_last_payment;
        }
    }
    else if(single != -1 && search){
        cout << "\n\n* Name: " << current_clients[single].name;
        cout << "\n* Address " << current_clients[single].address;
        cout << " " << current_clients[single].city_state_zip;
        cout << "\n* Phone Number: " << current_clients[single].phone_number;
        cout << "\n* Account Balance: $ " << current_clients[single].account_balance;
        cout << "\n* Date of Last Payment: " << current_clients[single].date_last_payment << "\n";
    }
    else{
        cout << "\n\nValue not found in database!\n";
    }
}
void phoneNumberbasedSorter(vector<Customer>& current_customers){

    string minValue;
    short minIndex;
    for(short startSearch = 0; startSearch < current_customers.size(); startSearch++){
        minIndex = startSearch;
        minValue = current_customers[minIndex].phone_number;

        for(short index = startSearch + 1; index < current_customers.size(); index++){
            if(current_customers[index].phone_number < minValue){
                minValue = current_customers[index].phone_number;
                minIndex = index;
            }
        }
    
    swap(current_customers[minIndex], current_customers[startSearch]);
    }

}
short phoneNumberSearch(vector<Customer> current_customers, string search_value){
    short first = 0, last = current_customers.size() - 1, mid;

    bool found = false;
    while(!found && first <= last){
        mid = (first + last) / 2;

        if(current_customers[mid].phone_number == search_value)
            found = true;
        else if(search_value > current_customers[mid].phone_number)
            first = mid + 1;
        else 
            last = mid - 1;
    }
    if(!found)
        mid = -1;
    return mid;
}

void modifyClient(vector<Customer>& current_clients, short index_c){
    Customer new_client;

    cin.ignore();
    cout << "\nEnter new client's name: ";
    getline(cin, new_client.name);

    cout << "\nEnter address: ";
    getline(cin, new_client.address);

    cout << "\nEnter city, state, zip: ";
    getline(cin, new_client.city_state_zip);

    do{
        cout << "\nEnter phone number [(000) 000-0000]: ";
        getline(cin, new_client.phone_number);
    }while(validatePhoneNumber(new_client.phone_number));

    do{
        cout << "\nEnter account balance: ";
        cin >> new_client.account_balance;
    }while(validateUserInput(new_client.account_balance, 0, new_client.account_balance));

    do{
        cin.ignore();
        cout << "\nEnter date of last payment: ";
        getline(cin, new_client.date_last_payment);
    }while(!verifyDateInput(new_client.date_last_payment));

    swap(current_clients[index_c], new_client);

}
