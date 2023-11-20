#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Shape.h"
class CircleComposite: public Shape{
    Point x;
    int radius;
public:
    CircleComposite();
    CircleComposite(Point x, int radius, Color col);
    CircleComposite(int a,int b, int radius, Color col);
    void setX(Point x);
    Point getX();
    void draw();
    friend ostream & operator << (ostream &out, const CircleComposite &s);
    friend istream & operator >> (istream &in,  CircleComposite &s);
};

#endif // CIRCLE_H_INCLUDED
