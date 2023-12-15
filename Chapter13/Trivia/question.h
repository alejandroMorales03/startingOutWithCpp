#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
using namespace std;

class Question{
    private:
        string triv_quest;
        string correct_triv;
        string one_triv, two_triv, three_triv, four_triv;

    public:
        Question(string question, string ans_one, string ans_two, string ans_three, string ans_four);
        void setQuestion(string question);
        void setCorrectAnwer(string question);
        bool checkAnswer(string answer);
        string getCorrectAnswer()const;;

        string getQuestion()const;
        string getAnswerOne()const;
        string getAnswerTwo()const;
        string getAnswerThree()const;
        string getAnswerFour()const;
};

#endif