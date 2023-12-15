#include "Date.h"
#include <iostream>

using namespace std;

using namespace std;

int main(){
    Date myBirthday(4, 7, 2003);

    cout << "\n";
    myBirthday.NumbFormat();

    cout << "\n";
    myBirthday.MixedFormat();

    cout << "\n";
    myBirthday.StringFormat();

    cout << "\n";
    return 0;
}