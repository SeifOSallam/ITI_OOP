#include <iostream>
#include "graphics.h"
#include "Classes.h"

using namespace std;

CircleComposite::CircleComposite(){
    this->color = Color::BLACK;
    this->radius = 100;
}
CircleComposite::CircleComposite(Point x, int radius, Color col) {
    this->x = x;
    this->radius = radius;
    this->color = col;
}
CircleComposite::CircleComposite(int a,int b, int radius, Color col){
    Point p1(a,b);
    this->x = p1;
    this->radius = radius;
    this->color = col;
}
void CircleComposite::setX(Point x) {
    this->x = x;
}
Point CircleComposite::getX(){
    return x;
}
void CircleComposite::draw() {
    setcolor(static_cast<int>(this->color));
    circle(this->x.getX(), this->x.getY(), this->radius);
}

ostream & operator << (ostream &out, const CircleComposite &c)
{
    out<<"Circle-------"<<endl;
    out<<c.x;
    return out;
}

istream & operator >> (istream &in,  CircleComposite &c)
{
    in>>c.x;
    return in;
}



