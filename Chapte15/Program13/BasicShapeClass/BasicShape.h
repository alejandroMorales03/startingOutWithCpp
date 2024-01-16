#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape{
    protected:
        double area;
    public:
        double getArea()const;
        virtual void calcArea() = 0;

        virtual ~BasicShape();
};

#endif