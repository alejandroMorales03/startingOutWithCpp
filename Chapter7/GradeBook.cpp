#include <iostream>
using namespace std;

void Populator(string[], float[][4], float[], bool);
void Grader(string[], float[]);
bool inputVal(float, float, float);

int main(){
    string student_names[5];
    float student_tests[5][4];
    float average[5];
    short choice;


    do{
        cout << "\nWould you like to drop the lowest score for each student: \n\n1. Use All\n2. Drop Lowest";
        cout << "\n\nSelection: ";
        cin >> choice;
    }while(!inputVal(--choice, 1, 0));
    cin.ignore();;
    Populator(student_names, student_tests, average, choice);

    
    Grader(student_names, average);
    return 0;

    

}

/**
 * @brief Populates the names array with user input and records the set of 4 scores for each stuent
 * 
 * @param names 
 * @param scores 
 */
void Populator(string names[], float scores[][4], float average[], bool drop){
    float lowest = 100;
    for(short index = 0; index < 5; index++){
        cout << "\nStudent " << (index + 1) << " name: ";
        getline(cin, names[index]);
        average[index] = 0;
        for(short score = 0; score < 4; score++){
            do{
                cout << "Score " << (score + 1) << ": ";
                cin >> scores[index][score];
            }while(!inputVal(scores[index][score], 100, 0));
            if(drop){
                if(scores[index][score] < lowest)
                    lowest = scores[index][score];
            }
            average[index] += scores[index][score];
        }
        if(drop){
            average[index] -= lowest;
            average[index] /= 3;
        }
        else
            average[index] /= 4;
        cin.ignore();
    }
}

/**
 * @brief performs input validation
 * 
 * @param check 
 * @param max 
 * @param min 
 * @return true 
 * @return false 
 */
bool inputVal(float check, float max, float min){
    if(check <= max && check >= min)
        return true;
    else{
        cout << "\nERROR: MUST BE POSITIVE VALUES\n\n";
        return false;
    }
}

/**
 * @brief Displays the students averge along with their letter grade
 * 
 * @param names 
 * @param average 
 */
void Grader(string names[], float average[]){
    cout << "\nGrades...\n\n";
    for(short index = 0; index < 5; index++){
        cout << names[index] << ": " << average[index] << " ";
        if(average[index] >= 90)
            cout << "A\n";
        else if(average[index] >= 80)
            cout << "B\n";
        else if(average[index] >= 70)
            cout << "C\n";
        else if(average[index] >= 60)
            cout << "D\n";
        else
            cout << "F\n";
    
    }
}

