#include "Die.h"
#include <ctime>
#include <cstdlib>


Die::Die(){
    points = 0;
    srand(time(0));
}
short Die::Roll(){
    sideUp = (rand() % (6 - 1 + 1) + 1);
    return sideUp;
}

void Die::updatePoints(){
    switch(sideUp){
        case 1:
            points += 30;
            break;
        case 2:
            points += 17;
            break;
        case 3:
        case 5:
            points += 10;
            break;
        case 4:
            points += 20;
            break;
        case 6:
            points += 5;
            break;


    }

}

string Die::checkCaught(){
    string message;
    switch(sideUp){
        case 1:
            message = "Huge Fish";
            break;
        case 2:{
            message =  "Letter in a Bottle";
            break;
        }
        case 3:
        case 5:
            message =  "Rusty Anchor";
            break;
        case 4:
            message = "Small Shark";
            break;
        case 6:
            message =  "Little Fish";
            break;
    }
    updatePoints();
    return message;
}

short Die::getPoints()const{
    return points;
}
string Die::getMessage() const{
    return points > 100 ? "Great Fishing!!" : points > 50? "Not your best day!!" : "You could have done better!!";
}
