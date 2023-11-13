#include <iostream>
#include <iomanip>

using namespace std;

short num_students, num_tests;
struct StudentInfo{
    string name;
    string ID; 
    float* tests_list;
    float average;
    char grade;
};
enum THRESHOLDS{A = 91, B = 81, C = 71, D = 61, F = 0};


bool validateUserInput(float, float, float);

StudentInfo* getDimensions();
void getStudentsInfo(StudentInfo*);
short getBestWidth(StudentInfo*);
void calcAverage(StudentInfo*);
void assignGrade(StudentInfo*);
void printInfo(StudentInfo*);
bool validateID(string);

int main(){
    cout << setprecision(2) << fixed;
    StudentInfo* new_course = getDimensions();
    getStudentsInfo(new_course);
    calcAverage(new_course);
    assignGrade(new_course);
    printInfo(new_course);

    for(short index = 0; index < num_students; index++){
        delete[] new_course[index].tests_list;
        new_course[index].tests_list = nullptr;
    }

    delete[] new_course;
    new_course = nullptr;
    return 0;
}


bool validateUserInput(float test, float min, float max){
    if(test >= min && test <= max)
        return false;
    cout << "\nINVALID ENTRY\n\n";
    return true;
}
StudentInfo* getDimensions(){
   StudentInfo* new_course = nullptr;
    do{
        cout << "\nHow many students are enrolled in the course: ";
        cin >> num_students;
    }while(validateUserInput(num_students, 1, num_students));
    new_course = new StudentInfo[num_students];

    do{
        cout << "\nHow many tests will be assigned in the course: ";
        cin >> num_tests;
    }while(validateUserInput(num_tests, 0, num_tests));

    for(short index = 0; index < num_students; index++)
        new_course[index].tests_list = new float[num_tests];  

    return new_course; 
}
void getStudentsInfo(StudentInfo* students){
    for(short index = 0; index < num_students; index++){
        cin.ignore();
        cout << "\nEnter student name: ";
        getline(cin, students[index].name);

        do{
            cout << "Enter student ID number: ";
            getline(cin, students[index].ID);
        }while(validateID(students[index].ID));

        for(short ind_t = 0; ind_t < num_tests; ind_t++){
            do{
                cout << "Enter score for test #" << (ind_t + 1) << ": ";
                cin >> students[index].tests_list[ind_t];
            }while(validateUserInput(students[index].tests_list[ind_t], 0, 100));
        }
    }
}
bool validateID(string ID){
    bool isInvalid = false;
    if(ID.length() != 6)
        isInvalid = true;

    for(short index = 0; index < ID.length() && !isInvalid; index++){
        if(!isalnum(ID.at(index)))
            isInvalid = true;
    }
    if(isInvalid)
        cout << "\nINVALID ID\n\n";

    return isInvalid;
}
void calcAverage(StudentInfo* students){

    for(short index = 0; index < num_students; index++){
        students[index].average = 0;

        for(short ind_t = 0; ind_t < num_tests; ind_t++){
            students[index].average += students[index].tests_list[ind_t];
        }

        students[index].average /= num_tests;
    }

}
void assignGrade(StudentInfo* students){

    for(short index = 0; index < num_students; index++){
        if(students[index].average > A)
            students[index].grade = 'A';
        else if(students[index].average > B)
            students[index].grade = 'B';
        else if(students[index].average > C)
            students[index].grade = 'C';
        else if(students[index].average > D)
            students[index].grade = 'D';
        else
            students[index].grade = 'F';
    }
}
short getBestWidth(StudentInfo* students){
    short ideal_width = 0;
    for(short index = 0; index < num_students; index++){
        if(students[index].name.length() > ideal_width)
            ideal_width =  students[index].name.length();
    }
    return ideal_width;
}
void printInfo(StudentInfo* students){
    short ideal_width = getBestWidth(students);

    cout << "\n" << setw(ideal_width) << "Name" << "\tID Number\tAvg Test Score\tGrade\n\n";

    for(short index = 0; index < num_students; index++){
        cout << setw(ideal_width) << students[index].name << "\t";
        cout << setw(6) << students[index].ID << "\t\t";
        cout << setw(10) << students[index].average << "\t\t";
        cout << setw(4) << students[index].grade << "\n";
    }
    cout << "\n";
}
