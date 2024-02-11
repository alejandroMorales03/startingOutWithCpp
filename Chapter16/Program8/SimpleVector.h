#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <algorithm>
#include <iostream>

template <class Type>

class SimpleVector{
    private:
        int size;
        Type* ptr;
        int count;

    public:
        SimpleVector(int size);
        SimpleVector(int size, Type value);

        ~SimpleVector();

        void push(Type value);
        void pop();
        void clear();
        void shrink();
        Type* search(Type value);

        int elements() const;
        int capacity()const;

        void display()const;

        Type& operator[](int index);



        

};


template <class Type>
SimpleVector<Type>::SimpleVector(int size) : size(size), ptr(nullptr), count(0){
    ptr = new Type[size];
}

template <class Type>
SimpleVector<Type>::SimpleVector(int size, Type value) : SimpleVector(size){
    count = size;
    for(int index = 0; index < size; index++){
        ptr[index] = value;
    }
}

template <class Type>
SimpleVector<Type>::~SimpleVector(){
    delete[] ptr;
    ptr = nullptr;
}

template <class Type>

void SimpleVector<Type>::push(Type value){
    
    Type* temporary_ptr = ptr;
    ptr = new Type[size + 1];
    std::copy(temporary_ptr, temporary_ptr + size, ptr);
    ptr[count] = value;
    count++;
    size++;

    delete [] temporary_ptr;
    std::sort(ptr, ptr  + size);
}

template <class Type>
void SimpleVector<Type>::pop(){
    count--;
}

template <class Type>
void SimpleVector<Type>::display()const{
   std::cout << "\n";
    for(short index = 0; index < count; index++){
        std::cout << ptr[index] << " ";
    }
}

template <class Type>
Type& SimpleVector<Type>::operator[](int index){
    return ptr[index];

}

template <class Type>
int SimpleVector<Type>::elements()const{
    return count;
}
template <class Type>
int SimpleVector<Type>::capacity()const{
    return size;
}

template <class Type>
void SimpleVector<Type>::clear(){
    delete[] ptr;
    ptr = nullptr;
    count = 0; 
    size = 0;
}

template <class Type>
void SimpleVector<Type>::shrink(){
    size = count;
}

template <class Type>
Type* SimpleVector<Type>::search(Type value){


    bool found = false;
    int first = 0, last = count - 1;
    int middle = (first + last)/2;
   

    while(!found && first <= last){
        if(value == ptr[middle])
            return &ptr[middle];
        else if(value > ptr[middle]){
            first = middle + 1;
        }
        else 
            last = middle - 1;
        middle = (first + last)/2;

    }
    return nullptr;



}



#endif

