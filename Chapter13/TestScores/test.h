#ifndef TEST_H
#define TEST_H

struct scoreSignal{
    float score;
    bool condition;
};

class test{
    private:
        int size;
        static const float MAX_SCORE;
        static const float MIN_SCORE;
        float* ptr_test;
        scoreSignal myIndexSignal;

        void inputValidation(int index, float value);

    public:
        test(int size = 1);
        scoreSignal getTest(int index);
        void setTest(int index, float score); 
        float getAverage()const;
        ~test();    
};



#endif