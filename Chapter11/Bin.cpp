#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Bin{
    string description;
    short count;
};

enum modifyChoice{ADD = 1, REMOVE = 2};

bool validateUserInput(float, float, float);
short getBestWidth(vector<Bin>&);
void printDB(vector<Bin>);
void descBasedSort(vector<Bin>&);
short descBasedSearch(vector<Bin>, string);
void modifyElement(Bin&, short, modifyChoice);



int main(){

    vector<Bin>inventory = {{"Valve", 10}, {"Bearing", 5}, {"Bushing", 15},
                    {"Coupling", 21}, {"Flange", 7}, {"Gear", 5},
                    {"Gear Housing", 5}, {"Vacuum Gripper", 25}, 
                    {"Cable", 18}, {"Rod", 12}};
    short choice;
    string descr_selec;

    do{
        printDB(inventory);
        cout << "\n1. Modify a Bin.";
        cout << "\n2. Exit";
        cout << "\n\nSelection: ";
        cin >> choice;

        if(choice == 1){
            cin.ignore();
            cout << "\nEnter the name of the item you'd like to to modify: ";
            getline(cin, descr_selec);

            descBasedSort(inventory);
            short index_f = descBasedSearch(inventory, descr_selec);

            if(index_f != -1){
                cout << "\n* * * BIN INFO * * * \n\n";
                cout << inventory[index_f].description << "\t" << inventory[index_f].count << "\n";
                
                short selection;
                do{
                    cout << "\n1. ADD ELEMENETS INTO BIN";
                    cout << "\n2. REMOVE ELEMENTS FROM BIN";
                    cout << "\n\nSelection: ";
                    cin >> selection;
                }while(validateUserInput(selection, ADD, REMOVE));

                short qty;
                cout << "\nHow many " << inventory[index_f].description << "s would you like to ";
                if(choice == 1)
                    cout << "add";
                else
                    cout << "remove";
                    
                cout << "\n\nSelection: ";
                cin >> qty;

                modifyElement(inventory[index_f], qty, static_cast<modifyChoice>(choice));
                
            }
            else{
                cout << "\nITEM NOT FOUND\n";
            }
        }
    }while(choice != 2);
    

}


short getBestWidth(vector<Bin>& invt) {
    short ideal_width = 0;
    for (short index = 0; index < invt.size(); index++) {
        if (invt[index].description.length() > ideal_width)
            ideal_width = invt[index].description.length();
    }
    return ideal_width;
}
void printDB(vector<Bin> invt){
   short width = getBestWidth(invt);

   cout << "\n" << setw(width) << "Description" << "\t" << "Qtty\n\n";

   for(short index = 0; index < invt.size(); index++){
        cout << setw(width) << invt[index].description << "\t" << setw(2) << invt[index].count << "\n";
   }
}
void descBasedSort(vector<Bin>& invent){

    string minValue;
    short minIndex;

    for(short startSearch = 0; startSearch < invent.size() - 1; startSearch++){
        minValue = invent[startSearch].description;
        minIndex = startSearch;

        for(short index = startSearch + 1; index < invent.size(); index++){
            if(invent[index].description < minValue){
                minValue = invent[index].description;
                minIndex = index;
            }
        }

        swap(invent[minIndex], invent[startSearch]);
    }

}
short descBasedSearch(vector<Bin>group, string key){
    short mid, first = 0, last = group.size() - 1;
    bool found = false;

    while(!found && first <= last){
        mid = (first + last)/2;

        if(key == group[mid].description)
            found = true;
        else if(key > group[mid].description)
            first = mid + 1;
        else
            last = mid -1;
    }

    if(!found)
        mid = -1;
    return mid;
}
bool validateUserInput(float test, float min, float max){
    if(test <= max && test >= min)
        return false;
    cout << "\n[ERROR] INVALID ENTRY\n";
    return true;
}

void modifyElement(Bin& item, short qty, modifyChoice choice){
    if(choice == 1){
        if(item.count + qty > 30){
            cout << "\nOnly " << 30 - item.count <<  " " << item.description << "s were added due to space constraints" << "\n";
            item.count = 30;
        }
        else
            item.count += qty;
    }
    else{
         if(item.count - qty < 30){
            cout << "\nOnly " << item.count << " " <<  item.description << "s were removed" << "\n";
            item.count = 0;
        }
        else
            item.count -= qty;
    }
}