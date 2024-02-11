#include "TestScores.h"
#include <new>

TestScores::TestScores(float* ptr, int SIZE) : scores(nullptr), size(SIZE){

    if(size < 1)
        throw std::bad_alloc();
    scores = ptr;

    for(short index = 0; index < SIZE; index++){
        if(scores[index] < 0 || scores[index] > 100)
            throw InvalidScore(scores + index);
    }

}

TestScores::InvalidScore::InvalidScore(float* score_arg) : score_exc(score_arg){
    message = std::to_string(*score_arg) + " IS AN INVALID SCORE\n";
}

std::string TestScores::InvalidScore::getMessage()const{
    return message;
}

float TestScores::average(){

    int sum = 0;
    for(short index = 0; index < size; index++){
        sum += scores[index];
    }
    return sum/size;
}