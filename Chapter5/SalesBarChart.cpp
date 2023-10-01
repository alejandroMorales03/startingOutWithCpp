#include <iostream>
using namespace std;

int main(){
//arrays have not been covered but it's the most convinient way of doing this

float stores[5];
cout << "\n";
for(short index = 0; index < 5; index++){
    cout << "Enter sales for store " << (index + 1) << ": ";
    cin >> stores[index];
}

cout << "\nSales Bar Chart\n(Each * = $ 100)\n";

for(short index = 0; index < 5; index++){
    cout << "\nStore " << (index + 1) << ": ";
    for(short star = 0; star < static_cast<int>(stores[index] / 100) ; star++){
        cout << "*";
    }
}

cout << "\n\n";

}