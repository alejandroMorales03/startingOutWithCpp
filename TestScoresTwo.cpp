#include <iostream>
using namespace std;

short getStudents();
void getNamesAndScores(string*, float*, short);
void Sorter(string*, float*, short);
void Printer(string*, float*, short);

int main(){
    short size = getStudents();
    string* names = nullptr;
    float* scores = nullptr;

    if(size > 0){
        names = new string[size];
        scores = new float[size];

        if(names && scores){
            getNamesAndScores(names, scores, size);
            Sorter(names, scores, size);
            Printer(names, scores, size);

            delete [] names;
            names = nullptr;
            delete [] scores;
            scores = nullptr;
        }

    }
    return 0;
}
/**
 * @brief Get the Students object
 * 
 * @return short 
 */
short getStudents(){
    short students;
    cout << "\nHow many students are in the class: ";
    cin >> students;
    return students;
}

/**
 * @brief Get the Names And Scores object
 * 
 * @param names 
 * @param scores 
 * @param size 
 */
void getNamesAndScores(string* names, float* scores, short size){
    cout << "\nEnter: \n";
    for(short index = 0; index < size; index++){
        cin.ignore();
        cout << "\nStudent " << (index + 1) << "'s name: ";
        getline(cin, *(names + index));

        do{
            cout << *(names + index) << "'s score: ";
            cin >> *(scores + index);
            if(*(scores + index) < 0)
                cout << "\nINVALID INPUTn\n\n";
        }while(*(scores + index) < 0);
    }
}

/**
 * @brief Sorts the scores array in ascending order and makes modifications to the names array so that values coincide
 * 
 * @param names 
 * @param scores 
 * @param size 
 */
void Sorter(string* names, float* scores, short size){
    short maxScore, maxIndex;
    string MaxName;

    for(short startScan = 0; startScan < size - 1; startScan++){
        maxIndex = startScan;
        maxScore = *(scores + startScan);

        for(short index = startScan + 1; index < size; index++){
            if(*(scores + index) > maxScore){
                maxScore = *(scores + index);
                maxIndex = index;
                MaxName = *(names + index);
            }
        }

        *(scores + maxIndex) = *(scores + startScan);
        *(names + maxIndex) = *(names + startScan);
        *(scores + startScan) = maxScore;
        *(names + startScan) = MaxName;
    }
}

/**
 * @brief Prints the contents of arrays 
 * 
 * @param names 
 * @param scores 
 * @param size 
 */
void Printer(string* names, float* scores, short size){

    for(short index = 0; index < size; index++){
        cout << "\n" << *(names + index) << " " << *(scores + index);
    }
    cout << "\n\n";
}