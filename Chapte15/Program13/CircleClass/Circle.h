#ifndef CIRCLE_H
#define CIRCLE_H

#include "/Users/alejandromorales/projects/Chapte15/Program13/BasicShapeClass/BasicShape.h"

class Circle : public BasicShape{
    private:
        static const double PI;
        double centerX;
        double centerY;
        double radius;
    public:
        Circle(double xCent, double yCent, double radius);

        void calcArea() override;

        double getXCoordinate()const;
        double getYCoordinate()const;

        virtual ~Circle();

};

#endif