#ifndef TESTSORES_H
#define TESTSORES_H
#include <iostream>
class TestScores{
    private:
        float* scores;
        int size;

    public:

        class InvalidScore{
            private:
                float* score_exc;
                std::string message;
            public:
                InvalidScore(float* score_arg);
                std::string getMessage() const;

        };

        TestScores(float* ptr, int SIZE);
        float average();
};

#endif