#include <iostream>

using namespace std;

int doSomething(int*, int*);

int main(){
    int one = 4, two = 34;
    cout << "\n" << doSomething(&one, &two) << "\n\n";
    return 0;
}

int doSomething(int* val_one, int* val_two){
    int temp = *val_one;
    *val_one = *val_one * 10;
    *val_two = temp * 10;
    return *val_one + *val_two;
}