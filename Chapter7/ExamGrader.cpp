#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

void writeToFile(ofstream&);
void readFromFile(ifstream& , char[]);
void Grader(char[], char[]);

int main(){
    ofstream right_answers_ofile("/Users/alejandromorales/Desktop/Projects/Chapter7/rightanswers.txt");
    if(!right_answers_ofile.fail()){
        writeToFile(right_answers_ofile);
        right_answers_ofile.close();
    }
    else{
        cout << "\nERROR: RIGHT ANSWERS COULD NOT BE SAVED...";
        exit(0);
    }

    ofstream student_answers_ofile("/Users/alejandromorales/Desktop/Projects/Chapter7/student_answers.txt");
    if(!student_answers_ofile.fail()){
        this_thread::sleep_for(chrono::seconds(1));
        writeToFile(student_answers_ofile);
        student_answers_ofile.close();
    }
    else{
        cout << "\nERROR: STUDENT ANSWERS COULD NOT BE SAVED...";
        exit(0);
    }

    char right_answers[20], student_answers[20];
    ifstream right_answers_ifile("/Users/alejandromorales/Desktop/Projects/Chapter7/rightanswers.txt");
    if(!right_answers_ifile.fail()){
        readFromFile(right_answers_ifile, right_answers);
    }
    else{
        cout << "\nERROR: RIGHT ANSWERS COULD NOT BE READ...";
        exit(0);
    }

    ifstream student_answers_ifile("/Users/alejandromorales/Desktop/Projects/Chapter7/student_answers.txt");
    if(!student_answers_ifile.fail()){
        readFromFile(student_answers_ifile, student_answers);
    }
    else{
        cout << "\nERROR: STUDENT ANSWERS COULD NOT BE READ...";
        exit(0);
    }

    Grader(right_answers, student_answers);
    return 0;

    

}

/**
 * @brief takes an file object and writes a series of characters to it
 * 
 * @param writeFile 
 */
void writeToFile(ofstream& writeFile){
    srand(time(0));
    for(short counter = 0; counter < 20; counter++){
        writeFile << static_cast<char>((rand() % (68 - 65 + 1) + 65));
        if(counter!= 19)
            writeFile<< "\n";
    }

}

/**
 * @brief reads characters from a file into an array
 * 
 * @param right_answers_file 
 * @param right_answers 
 */
void readFromFile(ifstream& right_answers_file, char right_answers[]){
    short index = 0;
    while(right_answers_file >> right_answers[index]){
        index++;
    }
}

/**
 * @brief List all wrong questios with right and given answers and determines if the student passed or not
 * 
 * @param right 
 * @param student 
 */
void Grader(char right[], char student[]){
    short wrong = 0;
    float accuracy;
    cout << "\nMissed Questions\n\nQuestion\tRight Answer\tYour Answer\n\n";
    for(short index = 0; index < 20; index++){
        if(right[index] != student[index]){
            cout << (index + 1) << ".\t" << right[index] << "\t" << student[index] << "\n";
            wrong++;
        }
    }
    accuracy = (20 - wrong) / 20.0 * 100;
    cout << "\nTotal Missed Questions: " << wrong;
    cout << "\nPercent Accuracy:        " << accuracy;
    if(accuracy >= 70)
        cout << "\nPASS\n\n";
    else
        cout << "\nFAIL\n\n";
}

