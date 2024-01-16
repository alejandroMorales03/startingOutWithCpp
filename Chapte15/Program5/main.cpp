#include <iostream>
#include "/Users/alejandromorales/projects/Chapte15/Program5/TimeClock/TimeClock.h"

int main(){
    TimeClock temporizer(1559, 2359);
    std::cout << "\nTime passed: " << temporizer.getElapsed() << "\n\n";
    return 0;
}