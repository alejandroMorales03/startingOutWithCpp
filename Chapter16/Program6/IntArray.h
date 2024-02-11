#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>

class IntArray{
    private:
        int size;
        int* ptr;

        void allocation();

    public:
        IntArray(int size);
        IntArray(int size, int value);

        int getSize() const;
        
        int getValueAtIndex(int index) const;
        int getLocation(int value);

        void setValueAtIndex(int index, int value);

        void display();

        ~IntArray();

        class OutOfBoundsException{
            private:
                std::string message;
            public:
                OutOfBoundsException(int size);

                std::string getErrorMessage()const;
           
        };



        

    
    
};

#endif