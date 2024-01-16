#include "/Users/alejandromorales/projects/Chapte15/Program13/BasicShapeClass/BasicShape.h"
#include "/Users/alejandromorales/projects/Chapte15/Program13/CircleClass/Circle.h"
#include "/Users/alejandromorales/projects/Chapte15/Program13/Rectangle/Rectangle.h"
#include <iostream>


using namespace std;

int main(){
    Circle myCircle(10, -20, 40);
    cout << "\nCircle Area: " << myCircle.getArea();
    Rectangle myRec(10, 20);
    cout << "\nRectangle Area: " << myRec.getArea();
    cout << "\n\n";

    

    return 0;
}