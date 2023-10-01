#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main(){

    ofstream writeFile("/workspaces/startingOutWithCpp/Chapter5/Random.txt");
    if(writeFile.fail())
        cout << "\nError opening wrting file...";
    else{
        srand(time(0));
        for(short i = 0; i < 1000; i++)
            writeFile << (rand() % (1000 - 1 + 1) + 1)<< "\n";
        writeFile.close();
    }

    ifstream readFile("/workspaces/startingOutWithCpp/Chapter5/Random.txt");
    if(readFile.fail())
        cout << "\nError opening reading file...";
    else{
        double holder, total = 0, average;
        short counter = 0;
        
        while(readFile >> holder){
            counter++;
            total += holder;
        }

        counter = counter == 0? 1 : counter;
        readFile.close();
        cout << "\nTotal numbers: " << counter;
        cout << "\nTotal: " << total;
        cout << "\nAverage: " << total / counter;
    }
    cout << "\n\n";
    return 0;


}