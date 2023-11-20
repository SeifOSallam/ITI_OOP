#include <iostream>
#include "graphics.h"
#include "Line.h"

using namespace std;

Lne::Lne() {
    this->color = Color::BLACK;
}
Lne::Lne(Point x, Point y, Color col) {
    this->x = x;
    this->y = y;
    this->color = col;
}
Lne::Lne(int a, int b, int c, int d, Color col) {
    Point p1(a,b);
    Point p2(c,d);
    this->x = p1;
    this->y = p2;
    this->color = col;

}
void Lne::draw() {
    setcolor(static_cast<int>(this->color));
    line(this->x.getX(),this->x.getY(),this->y.getX(),this->y.getY());
}

ostream & operator << (ostream &out, const Lne &c)
{
    out<<"Line---------"<<endl;
    out<<c.x;
    out<<c.y;
    return out;
}

istream & operator >> (istream &in,  Lne &c)
{
    in>>c.x;
    in>>c.y;
    return in;
}
