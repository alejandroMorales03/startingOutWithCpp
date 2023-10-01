#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream readFile("/workspaces/startingOutWithCpp/Chapter5/Students.txt");
    if(readFile.fail()){
        cout << "\nError opening file";
    }
    else{
        string first, last, holder;
        if(getline(readFile, holder))
            first = last = holder;
        while(getline(readFile, holder)){
            first = first.compare(holder) < 0? first : holder;
            last = last.compare(holder) > 0? last : holder;
        }
        readFile.close();
        cout << "\nFirst: " << first;
        cout << "\nLast:  " << last;

    }
    cout << "\n\n";
    return 0;
}