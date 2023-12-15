#include "question.h"
#include <iostream>

using namespace std;

int main(){
    Question myTriviaList[] = {Question(string("What is the capital city of Australia?"), string("Canberra"), string("Sydney"), string("Melbourne"), string("Brisbane")),
                               Question(string("Which planet is known as the \"Red Planet\"?"), string("Mars"), string("Venus"), string("Jupiter"), string("Saturn")),
                               Question(string("Who wrote the play \"Romeo and Juliet\"?"), string("William Shakespeare"), string("Charles Dickens"), string("Jane Austen"), string("Mark Twain")),
                               Question(string("In which year did the Titanic sink?"), string("1912"), string("1905"), string("1925"), string("1935")),
                               Question(string("What is the largest mammal in the world?"), string("Blue Whale"), string("Elephant"), string("Giraffe"), string("Rhinoceros")),
                               Question(string("Who is the author of the Harry Potter book series?"), string("George R.R. Martin"), string("Suzanne Collins"), string("J.K. Rowling"), string("J.R.R. Tolkien")),
                               Question(string("What's the chemical symbol for gold?"), string("Ag"), string("Au"), string("Cu"), string("Fe")),
                               Question(string("Which country is known as the \"Land of the Rising Sun\"?"), string("South Korea"), string("Vietnam"), string("China"), string("Japan")),
                               Question(string("What is the capital city of France?"), string("Rome"), string("Berlin"), string("Madrid"), string("Paris")),
                               Question(string("Who painted the Mona Lisa?"), string("Vincent van Gogh"), string("Leonardo da Vinci"), string("Pablo Picasso"), string("Michelangelo"))};

    myTriviaList[0].setCorrectAnwer("Sydney");
    myTriviaList[1].setCorrectAnwer("Mars");
    myTriviaList[2].setCorrectAnwer("William Shakespeare");
    myTriviaList[3].setCorrectAnwer("1912");
    myTriviaList[4].setCorrectAnwer("Blue Whale");
    myTriviaList[5].setCorrectAnwer("J.K. Rowling");
    myTriviaList[6].setCorrectAnwer("Au");
    myTriviaList[7].setCorrectAnwer("Japan");
    myTriviaList[8].setCorrectAnwer("Paris");
    myTriviaList[9].setCorrectAnwer("Leonardo da Vinci");

    int player_one = 0, player_two = 0;
    string answer;

    for(short index = 0; index < 10; index++){
        if(index % 2 == 0 || index == 0)
            cout << "\nQuestion for Player 1: ";
        else
            cout << "\nQuestion for Player 2: ";

        cout <<  myTriviaList[index].getQuestion() << "\n";
        cout << "\n" << myTriviaList[index].getAnswerOne();
        cout << "\n" << myTriviaList[index].getAnswerTwo();
        cout << "\n" << myTriviaList[index].getAnswerThree();
        cout << "\n" << myTriviaList[index].getAnswerFour();

        cout << "\n\nEnter answer: ";
        getline(cin, answer);

        if(myTriviaList[index].checkAnswer(answer)){
            cout << "\n+ 10 Points\n";\
            if(index % 2 == 0 || index == 0)
                player_one += 10;
            else
                player_two += 10;
        }
        else{
            cout << "\nRIGHT ANSWER: " << myTriviaList[index].getCorrectAnswer();
            cout << "\nYOUR ANSWER:  " << answer << "\n";
        }
    }

    cout << "\nPlayer 1: " << player_one << " points";
    cout << "\nPlayer 2: " << player_two << " points" << "\n\n";
 
    return 0;
}