#include "/Users/alejandromorales/projects/Chapte15/Program6/GradedActivityClass/GradedActivity.h"
#include "/Users/alejandromorales/projects/Chapte15/Program6/EssayClass/Essay.h"
#include <iostream>

using namespace std;

int main(){

    GradedActivity myGrade(139.99, 120, 200, 180, 160, 140, 120);
    cout << myGrade.getGrade() << "\n";
    cout << myGrade.getLetterGrade() << "\n";
    cout << myGrade.passOrFail() << "\n\n";

    Essay myEssay(30, 20, 20, 30);
    cout << myEssay.getGrade() << "\n";
    cout << myEssay.getLetterGrade() << "\n";
    cout << myEssay.passOrFail() << "\n\n";

    std::unique_ptr<GradedActivity>otherEssay(new Essay(10, 10, 10, 10));
    cout << otherEssay->getGrade() << "\n";
    cout << otherEssay->getLetterGrade() << "\n";
    cout << otherEssay->passOrFail() << "\n\n";

    return 0;
}