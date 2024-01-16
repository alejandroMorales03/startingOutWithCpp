#include "Essay.h"
#include <iostream>

Essay::Essay(double grammarScore, double spellingScore, double lengthScore, double contentScore) : GradedActivity(){
    if(grammarScore > Grammar || spellingScore > Spelling || lengthScore > Length || contentScore > Content)
        throw std::runtime_error("ASSIGNED SCORES IN ESSAY CLASS ARE HIGHER THAN CATEGORY LIMITS");

    grammar = grammarScore;
    spelling = spellingScore;
    length = lengthScore;
    content = contentScore;
    
    setGrade(grammar + spelling + length + content);
    determinePassOrFail();
    determineLetterGrade();
}