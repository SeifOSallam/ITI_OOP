#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include <iostream>
#include "Classes.h"
using namespace std;
class SquareComposite: public Shape{
    Point x;
    Point y;
public:
    SquareComposite();
    SquareComposite(Point x, Point y, Color col);
    SquareComposite(int a,int b,int c,int d, Color col);
    void setX(Point x);
    void setY(Point y);
    Point getX();
    Point getY();
    void draw();
    friend ostream & operator << (ostream &out, const SquareComposite &s);
    friend istream & operator >> (istream &in,  SquareComposite &s);
};
class SquareAssociated: public Shape{
public:
    SquareAssociated();
    void draw(Point x, Point y);
};
class SquareAggregated: public Shape{
    Point *x;
    Point *y;
public:
    SquareAggregated();
    SquareAggregated(Point *x, Point *y, Color col);
    SquareAggregated(int a,int b,int c,int d, Color col);
    void setX(Point *x);
    void setY(Point *y);
    Point* getX();
    Point* getY();
    void draw();
    friend ostream & operator << (ostream &out, const SquareAggregated &s);
    friend istream & operator >> (istream &in,  SquareAggregated &s);
};

#endif // SQUARE_H_INCLUDED
