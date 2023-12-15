#include "question.h"

Question::Question(string question, string ans_one, string ans_two, string ans_three, string ans_four){
    triv_quest = question;
    one_triv = ans_one;
    two_triv = ans_two;
    three_triv = ans_three;
    four_triv = ans_four;
}

void Question::setQuestion(string question){
    triv_quest = question;
}

string Question::getQuestion()const{
    return triv_quest;
}

string Question::getAnswerOne()const{
    return one_triv;
}

string Question::getAnswerTwo()const{
    return two_triv;
}

string Question::getAnswerThree()const{
    return three_triv;
}

string Question::getAnswerFour()const{
    return four_triv;
}
void Question::setCorrectAnwer(string question){
    correct_triv = question;
}

string Question::getCorrectAnswer()const{
    return correct_triv;
}

bool Question::checkAnswer(string answer){
    return answer == getCorrectAnswer();
}