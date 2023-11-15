#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>
using namespace std;

enum class Color {
    BLACK,
BLUE     ,
GREEN     ,
CYAN       ,
RED         ,
MAGENTA      ,
BROWN         ,
LIGHTGRAY      ,
DARKGRAY        ,
LIGHTBLUE        ,
LIGHTGREEN        ,
LIGHTCYAN          ,
LIGHTRED            ,
LIGHTMAGENTA         ,
YELLOW                ,
WHITE
};

class Point{
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    friend ostream & operator << (ostream &out, const Point &p);
    friend istream & operator >> (istream &in,  Point &p);
};

class Shape{
protected:
    Color color;
public:
    void setClr(Color x);
    Color getColor();
    virtual void draw();
};

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
class Lne: public Shape{
    Point x;
    Point y;
public:
    Lne();
    Lne(Point x, Point y, Color col);
    Lne(int a, int b, int c, int d, Color col);
    void draw();
    friend ostream & operator << (ostream &out, const Lne &l);
    friend istream & operator >> (istream &in,  Lne &l);
};

#endif // CLASSES_H_INCLUDED
