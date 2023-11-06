#include <iostream>
using namespace std;

void searchEntry(string, string[], int);
int main(){
    string value;
    cout << "Enter a search value: ";
    getline(cin, value);

    string data[] = {"Alejandra Cruz, 555-1223", "Joe Looney, 555-0097", "Geri Palmer, 555-8787",
                  "Li Chen, 555-1212", "Holly Gaddis, 555-8887", "Sam Wiggins, 555-0998",
                  "Bob Kain, 555-8712", "Tim Haynes, 555-7676", "Warren Gaddis, 555-9037", 
                  "Jean James, 555-4339", "Ron Palmer, 555-2783"};
    
    searchEntry(value, data, sizeof(data)/sizeof(data[0]));
    cout << "\n\n";


    return 0;
}

void searchEntry(string key, string data[], int size){
    for(short index = 0; index < size; index++){
        if(data[index].find(key, 0) != string::npos)
            cout << "\n" << data[index];
    }
}

