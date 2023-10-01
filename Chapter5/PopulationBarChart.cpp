#include <iostream>
#include <fstream>

using namespace std;

int main(){
    short yearPopulation[2][6] = {{1900, 1920, 1940, 1960, 1980, 2000}, {}};

    ifstream populationFionFile("/workspaces/startingOutWithCpp/Chapter5/People.txt");
    if(populationFionFile.fail())
        cout << "\nFile could not be open";
    else{
        cout << "\nReading File...\n";
        short counter = 0;
        while(populationFionFile >> yearPopulation[1][counter]){
            counter++;
        }
        populationFionFile.close();
        cout << "\nPRAIRIEVILLE POPULAION GROWTH\n(Each * represents 1,000 people)\n";
        for(counter = 0; counter < 6; counter++){
            cout << "\n" << yearPopulation[0][counter] << ": ";
            for(short index = 0; index < static_cast<int>(yearPopulation[1][counter]/1000); index++){
                cout << "*";
            }
        }
    }
    cout << "\n\n";
    return 0;
    
}