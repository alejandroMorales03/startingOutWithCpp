#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "/Users/alejandromorales/projects/Chapte15/Program13/BasicShapeClass/BasicShape.h"
class Rectangle : public BasicShape{
    private:
        double length;
        double width;
    public:
        Rectangle(double recLen, double recWidth);

        double getLength()const;
        double getWidth()const;

        void calcArea() override;

        ~Rectangle();
};

#endif