#include <iostream>
#include <iomanip>

using namespace std;

void getAnswers(char[], short);
bool inputVal(char);
void Score(char[], const char[], short = 15, short = 20);

int main(){
    const char correct_answers[] = {'A','D','B','B','C','B','A','B','C','D',
                                      'A','C','D','B','D','C','C','A','D','B'};

    char student_answers[20];
    getAnswers(student_answers, 20);
    Score(student_answers, correct_answers);
    return 0;
}

/**
 * @brief Get the Answers object
 * 
 * @param answers 
 * @param size 
 */
void getAnswers(char answers[], short size){
    cout << "\nEnter your ansnwer choice to each question: \n\n";
    for(short index = 0; index < size; index++){
        do{
            cout << "Question " << setw(2) << (index + 1) << ": ";
            answers[index] = cin.get();
            if(!inputVal(answers[index]))
                cout << "\nERROR: INVALID INPUT. MUST BE A,B,C, or D\n\n";
        }while(!inputVal(answers[index]));
                cin.ignore();
    }
}

/**
 * @brief checks for input validation
 * 
 * @param check 
 * @return true 
 * @return false 
 */
bool inputVal(char check){
    return (check >= 'A' && check <= 'D');
}

/**
 * @brief counts wrong questions, displays the number of right and wrong questions, and determines if the student passes
 * 
 * @param answers 
 * @param correct_answers 
 * @param threshold 
 * @param size 
 */
void Score(char answers[], const char correct_answers[], short threshold, short size){
    short pass = 0;
    cout << "\nWrong Questions: ";
    for(short index = 0; index < size; index++){
        if(answers[index] == correct_answers[index]){
            pass++;
        }
        else{
            cout << (index + 1) << " ";
        }
    }
    cout << "\nTotal Wrong Questions: " << (size - pass);
    cout << "\nTotal Right Questions: " << pass;
    if(pass >= threshold)
        cout << "\nYou passed!";
    else
        cout << "\nYou did not pass";
    cout << "\n\n";

}