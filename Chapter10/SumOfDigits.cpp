#include <iostream>

using namespace std;

short* SumOfDigits(string);
int main(){
    string numbers;

    cout << "Enter a string of nothing numbers: ";
    getline(cin, numbers);

    short* ptr_to_answers = SumOfDigits(numbers);
    
    cout << "\nTotal " << ptr_to_answers[0];
    cout << "\nLowest " << ptr_to_answers[1];
    cout << "\nHighest " << ptr_to_answers[2] << "\n";

    delete[] ptr_to_answers;
    ptr_to_answers = nullptr;


    return 0;
}

short* SumOfDigits(string line){
    short* answers = new short[3];
    answers[0] = 0;
    answers[1] = answers[2] = line.at(0) - '0';
    bool error = false;

    for(short index = 0; index < line.length() && !error; index++){
        if(!isdigit(line.at(index))){
            cout << "\nFull string could not be read\n";
            error = true;
        }
        else{
            answers[0] += line.at(index) - '0';
            if(line.at(index) < answers[1])
                answers[1] = line.at(index) - '0';
            else if(line.at(index) > answers[2])
                answers[2] = line.at(index) - '0';
        }
    }

    return answers;

}