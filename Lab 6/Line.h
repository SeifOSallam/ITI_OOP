#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include <iostream>
#include "Classes.h"
using namespace std;

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

#endif // LINE_H_INCLUDED
