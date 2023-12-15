#ifndef Narray_H
#define Narray_H

class Narray{
    private:
        float* value_array;
        float* sorted_array;
        int size;

        void sort();

    public:
        Narray(int size);
        ~Narray();
        void StoreElmnt(int index, float value);
        float getElmnt(int index) const;
        float getAverage() const;

        float getlowest() ;
        float getHighest() ;
};

#endif