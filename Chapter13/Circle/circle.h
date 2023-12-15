#ifndef CIRCLE_H
#define CIRCLE_H

class circle{
    private:
        float radius;
        static const float PI;

    public:
        circle();
        circle(float rad);
        void setRadius(float rad);
        float getRadius()const;
        float getArea()const;
        float getDiameter()const;
        float getCircumference()const;

};

#endif 