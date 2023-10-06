#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iomanip>                                                                                            

using namespace std;
const short JUDGES = 5;

void getJudgeData(float*);
void Printer(float*);
float calcScore(float* );
int main(){
    cout << setprecision(2) << fixed;
    float scores[JUDGES];
    getJudgeData(scores);
    cout << "\nPrinting Scores...\n\n";
    Printer(scores);
    cout << "Final score " << calcScore(scores) << "\n\n";
    

    return 0;
}

/**
 * @brief Generates random numbers between 0 and 10 including decimals and stores them in an array to hold the judges' scores
 * @param judge_array a pointer to an array of floats
 * @return nothing
*/
void getJudgeData(float* judge_array){
    srand(time(0));
    float value;

    for(short index = 0; index < JUDGES; index++){
        value = 0;
        do{
            value += (rand() % (10 - 0 + 1) + 0);
            this_thread::sleep_for(std::chrono::seconds(1));
            value += (rand() % (100 - 0 + 1) + 0) / 100.0;
        }while(value > 10 );
        judge_array[index] = value;
    }
}

/**
 * @brief Prints the values of array_arg
 * @param array_arg
 * @return nothing
*/
void Printer(float* array_arg){
    for(short index = 0; index < JUDGES; index++){
        cout << array_arg[index] << " ";
    }
    cout << "\n\n";
}

/**
 * @brief Calculates the average of the scores without taking into account the highest or lowest score
 * @param arg_arr a pointer to an array holding the scores
 * @return The average score
*/
float calcScore(float* arg_arr){
    float min = arg_arr[0], max = arg_arr[0], total = 0;
    short maxI, minI;

    for(short index = 0; index < JUDGES; index++){
        if(arg_arr[index] > max){
            maxI = index;
            max =  arg_arr[index];
        }
        if(arg_arr[index] < min){
            min = arg_arr[index];
            minI = index;
        }
        total += arg_arr[index];
    }

    total -= (arg_arr[minI] + arg_arr[maxI]);
    return (total / (JUDGES - 2));

    
}