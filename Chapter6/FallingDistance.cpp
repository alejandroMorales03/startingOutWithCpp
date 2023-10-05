#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const short TEST_VALUES = 10;
const float GRAV_CONST = 9.8, HALF = 0.5;

float fallingDistance(float);
void testFunction();

int main(){
    
testFunction();
return 0;

}

/**
 * @param float 
 * @return The distance traveled by a falling objcet givena time "time"
 * Description: The function calculates the falling distance of a time given a time
*/
float fallingDistance(float time){
    return HALF * GRAV_CONST * pow(time, 2);
}

/**
 * @param none
 * @return none
 * Description: Tests the function "fallingDistance" using values from 0 to 9
*/

void testFunction(){
    cout << "\nTime\t      Distance\n\n";
    for(short index = 0; index < TEST_VALUES; index++)
        cout << setw(2) << index  << " s\t" << setw(7) << fallingDistance(index) << " meters \n";
    cout << "\n";
}


