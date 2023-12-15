#include "circle.h"
#include <iostream>

using namespace std;

int main(){
    circle myCircle(13.5);
    cout << "\nDiameter: " << myCircle.getDiameter();
    cout << "\nArea: " << myCircle.getArea();
    cout << "\nCircumference: " << myCircle.getCircumference() << "\n\n";
    return 0;
}