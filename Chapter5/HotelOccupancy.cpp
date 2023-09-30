#include <iostream>

using namespace std;
int main(){

    unsigned short floors, total_rooms = 0, occupied_rooms = 0;
    float occupancy_rate;

    do{
        cout << "\nHow many floors does the hotel have: ";
        cin >> floors;
        if(floors < 1)
            cout << "\nINVALID INPUT!\n*The hotel must at least have one floor\n";
    }while(floors < 1);

    for(short c_floor = 1, rooms, occ_r; c_floor <= floors; c_floor++){
        if(c_floor == 13)
            continue;
        do{
            cout << "\nHow many rooms are in floor " << c_floor << ": ";
            cin >> rooms;
            if(rooms < 10)
                cout << "\nINVALID INPUT!\n*Rooms cannot be less than 10\n";
        }while(rooms < 10);
        total_rooms += rooms;
       
        do{
            cout << "How many rooms are occupied: ";
            cin >> occ_r;
            if(occ_r < 0 || occ_r > rooms)
                cout << "\nINVALID INPUT!\n*Rooms cannot be negative\n*There cannot be more occupied rooms than total rooms\n\n";
        }while(occ_r < 0 || occ_r > rooms);
        occupied_rooms += occ_r;
    }

    cout << "\nTotal Rooms: " << total_rooms;
    cout << "\nTotal Occupied Rooms: " << occupied_rooms;
    cout << "\nTotal Unoccupied Rooms: " << total_rooms - occupied_rooms;
    cout << "\nOccupancy Rate: " << static_cast<float>(occupied_rooms)/total_rooms << "\n\n";
    return 0;
}