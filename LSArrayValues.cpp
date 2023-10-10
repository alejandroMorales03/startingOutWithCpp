#include <iostream>
using namespace std;

void Populator(float[], short);
void findLandS(float[], float[], short, short);

int main(){
    float list[10];
    short size = 10;
    Populator(list, size);

    float answers[2];
    short ans_size = 2;
    findLandS(list, answers, size, ans_size);

    cout << "\nLargest Value: " << answers[1];
    cout << "\nSmallest Value: " << answers[0];
    cout << "\n\n";

}

/**
 * @param array_arg
 * @return void
 * @brief Uses a loop to populate an array
*/

void Populator(float array_arg[], short size){
    cout << "\nEnter 10 numbers: ";
    for(short index = 0; index < size; index++)
        cin >> array_arg[index];
}

void findLandS(float array_arg[], float answer[], short size_arg, short size_ans){
    answer[0] = array_arg[0];
    answer[1] = array_arg[0];

    for(short index = 1; index < size_ans; index++){
        answer[0] = array_arg[index] < answer[0]? array_arg[index] : answer[0];
        answer[1] = array_arg[index] > answer[1]? array_arg[index] : answer[1];
    }

}