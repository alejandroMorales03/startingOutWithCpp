#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

struct Invt{
    string description;
    short qty_hand;
    float wholesale;
    float retail;
    string date;

};
string getCurrDate();
bool isValid(float, float, float);

int main(){

    short choice;
    fstream record;
    Invt new_record;

    do{
        cout << "\n* * * Menu * * * \n";
        cout << "\n1. ADD NEW RECORD TO FILE";
        cout << "\n2. DISPLAY ANY RECORD IN FILE";
        cout << "\n3. CHANGE ANY RECORD IN FILE";
        cout << "\n4. EXIT";
        cout << "\n\nSELECTION: ";
        cin >> choice;

        switch(choice){
            case 1:{
                record.open("record.txt", ios::out|ios::app|ios::binary);
                if(!record.is_open() || record.fail())
                    cout << "\nFILE OPENING ERROR\n";
                else{
                    record.seekp(0L, ios::beg);
                    cout << "\nEnter the item description: ";
                    cin.ignore();
                    getline(cin, new_record.description);

                    do{
                        cout << "Enter the quanity on hand of the item: ";
                        cin >> new_record.qty_hand;
                    }while(!isValid(new_record.qty_hand, 0, new_record.qty_hand));

                    do{
                        cout << "Enter wholesale cost: ";
                        cin >> new_record.wholesale;
                    }while(!isValid(new_record.wholesale, 0, new_record.wholesale));

                    do{
                        cout << "Enter retail cost: ";
                        cin >> new_record.retail;
                    }while(!isValid(new_record.retail, 0, new_record.retail));

                    new_record.date = getCurrDate();
                    record.write(reinterpret_cast<char *>(&new_record), sizeof(new_record));
                    record.clear();
                    record.close();
                }
                break;
            }
            case 2:{
                record.open("record.txt", ios::in|ios::binary);
                if(!record.is_open() || record.fail())
                    cout << "\nFILE OPENING ERROR\n";
                else{
                    record.seekg(0L, ios::beg);
                    char signal = ' ';

                    cout << "\nPress ENTER to keep displaying records and press SPACE to stop: ";
                    cin.ignore();
                    signal = tolower(getchar());

                    while(!record.eof() && signal != 'e'){
                        if(record.read(reinterpret_cast<char *>(&new_record), sizeof(new_record))){
                            cout << "\nDescription: " << new_record.description;
                            cout << "\nQuantity on hand: "  << new_record.qty_hand;
                            cout << "\nWholesale Cost $: " << new_record.wholesale;
                            cout << "\nRetail Cost: $ " << new_record.retail;
                            cout << "\nDate Added: " << new_record.date;
                            cout << "\n* * * * * * * * * * * * * * * * ";
                            signal = tolower(getchar());
                        }
                    }
                    record.clear();

                    if(tolower(signal) != 'e')
                        cout << "\nNO MORE RECORDS TO BE DISPLAYED\n";

                    record.close();
                }
                break;
            }
            case 3:{
                record.open("record.txt", ios::in|ios::out|ios::ate|ios::binary);

                if(!record.is_open() || record.fail())
                    cout << "\nFILE OPENING ERROR\n";
                else{
                    string item_to_change;
                    cout << "\nEnter the item description of the record to modify: ";
                    cin.ignore();
                    getline(cin, item_to_change);

                    bool found = false;
                    
                    record.seekg(0, ios::beg);
                    while(!found && !record.eof()){
                        if(record.read(reinterpret_cast<char *>(&new_record), sizeof(new_record))){
                            if(item_to_change == new_record.description)
                                found = true;
                        }
                    }

                    if(found){
                        cout << "\nEnter the item description: ";
                        getline(cin, new_record.description);

                        do{
                            cout << "Enter the quanity on hand of the item: ";
                            cin >> new_record.qty_hand;
                        }while(!isValid(new_record.qty_hand, 0, new_record.qty_hand));

                        do{
                            cout << "Enter wholesale cost: ";
                            cin >> new_record.wholesale;
                        }while(!isValid(new_record.wholesale, 0, new_record.wholesale));

                        do{
                            cout << "Enter retail cost: ";
                            cin >> new_record.retail;
                        }while(!isValid(new_record.retail, 0, new_record.retail));
                        new_record.date = getCurrDate();  

                        record.seekp(-static_cast<long>(sizeof(new_record)), ios::cur);
                        record.write(reinterpret_cast<char *>(&new_record), sizeof(new_record));
                    }
                    else    
                        cout << "\nRECORD NOT FOUND\n";
                }
                record.clear();
                record.close();
                break;
            }
            case 4:{
                cout << "\nShutting Down...\n";
                break;
            }
            default:{
                cout << "\nINVALID ENTRY\n";
                break;
            }
        }   
    }while(choice != 4);
    cout << "\n";
    return 0;
}

string getCurrDate(){
    auto currentTime = chrono::system_clock::now();
    time_t currentTime_t = chrono::system_clock::to_time_t(currentTime);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime_t));
    return buffer;
}

bool isValid(float value, float min, float max){
    if(value >= min && value <= max)
        return true;
    cout << "\nINVALID ENTRY\n";
    return false;
}