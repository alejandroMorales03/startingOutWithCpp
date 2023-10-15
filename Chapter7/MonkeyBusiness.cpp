#include <iostream>
#include <iomanip>

using namespace std;

const short DAYS = 5, MONKEYS = 3;

float feedMonkeys(float[][DAYS], short);
bool inputVal(float, float, float);
short findExtreme(float[][DAYS], short, short);

int main(){
    float monkeyWeek[3][5];
    float total_food = feedMonkeys(monkeyWeek, MONKEYS);

    cout << setprecision(2) << fixed;

    cout << "\nTotal food eaten by all the monkeys:         " << setw(6) << total_food;
    cout << "\nAverage daily food eaten by all the monkeys: " << setw(6) << total_food/(MONKEYS * DAYS);
    cout << "\nMost food eaten by a monkey in a day:        " << setw(6) << findExtreme(monkeyWeek, 1, MONKEYS);
    cout << "\nLeast food eaten by a monkey in a day:       " << setw(6) << findExtreme(monkeyWeek, 0, MONKEYS) << "\n\n";
    return 0;
}

/**
 * @brief Performs input validation with user-entered data
 * 
 * @param check 
 * @param min 
 * @param max 
 * @return true 
 * @return false 
 */
bool inputVal(float check, float min, float max){
    return (check >= min && check <= max);
}

/**
 * @brief Records the food for each monkey for five days and returs the sum of all the food recorded
 * 
 * @param track 
 * @param MONKEYS 
 * @return float 
 */
float feedMonkeys(float track[][DAYS], short MONKEYS){
    float total_food = 0;
    cout << "\nEnter the following information: \n";
    for(short monkey_i = 0; monkey_i < MONKEYS; monkey_i++){
        cout << "\nEnter the food consumed by monkey " << (monkey_i + 1) << ": \n\n";
        for(short day_i= 0; day_i < DAYS; day_i++){
            do{
                cout << "Day " << (day_i + 1) << ": ";
                cin >> track[monkey_i][day_i];
                if(!inputVal(track[monkey_i][day_i], 0, track[monkey_i][day_i]))
                    cout << "\nERROR: INVALID INPUT. MUST BE POSITIVE\n\n";
            }while(!inputVal(track[monkey_i][day_i], 0, track[monkey_i][day_i]));
            total_food += track[monkey_i][day_i];
        }
    }
    return total_food;
}

/**
 * @brief finds the index correspondinf to the lowest or highest value
 * 
 * @param rainfall 
 * @param months 
 * @param maxOrMin 
 * @return short 
 */
short findExtreme(float monkeyWeek[][DAYS], short maxOrMin, short size){
    float compValue = monkeyWeek[0][0];
    short monkey = 0, day = 0;

    for(short monkey_i = 0; monkey_i < size; monkey_i++){
        for(short day_i = 0; day_i < DAYS; day_i++){
            if(maxOrMin == 0){
                if(monkeyWeek[monkey_i][day_i] < compValue){
                    compValue = monkeyWeek[monkey_i][day_i];
                    monkey = monkey_i;
                    day = day_i;
                }
            }
            else if(maxOrMin == 1){
                if(monkeyWeek[monkey_i][day_i] > compValue){
                    compValue = monkeyWeek[monkey_i][day_i];
                    monkey = monkey_i;
                    day = day_i;
                }
            }
        }
    }
    return monkeyWeek[monkey][day];
}