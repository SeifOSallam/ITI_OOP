#include <iostream>
#include "graphics.h"
#include "Classes.h"

using namespace std;

SquareComposite::SquareComposite(){
    this->color = Color::BLACK;
}
SquareComposite::SquareComposite(Point x, Point y, Color col) {
    this->x = x;
    this->y = y;
    this->color = col;
}
SquareComposite::SquareComposite(int a,int b,int c,int d, Color col) {
    Point p1(a,b);
    Point p2(c,d);
    this->x = p1;
    this->y = p2;
    this->color = col;
}

Point SquareComposite::getX() {
    return this->x;
}
Point SquareComposite::getY() {
    return this->y;
}
void SquareComposite::setX(Point x) {
    this->x = x;
}
void SquareComposite::setY(Point y) {
    this->y = y;
}

void SquareComposite::draw() {
    setcolor(static_cast<int>(this->color));
    line(this->getX().getX(),this->getX().getY(),this->getX().getX(),this->getY().getY());//Top Line
    line(this->getX().getX(),this->getX().getY(),this->getY().getX(),this->getX().getY());//Left Line
    line(this->getY().getX(),this->getY().getY(),this->getY().getX(),this->getX().getY());//Bottom Line
    line(this->getY().getX(),this->getY().getY(),this->getX().getX(),this->getY().getY());//Right Line
}

ostream & operator << (ostream &out, const SquareComposite &s)
{
    out<<"Square--------"<<endl;
    out<<"Point 1 : "<<s.x;
    out<<"Point 2 : "<<s.y;
    return out;
}

istream & operator >> (istream &in,  SquareComposite &s)
{
    Point p1,p2;
    cout << "Enter First Point: "<<endl;
    in >> p1;
    cout << "Enter Second Point: "<<endl;
    in >> p2;
    s.setX(p1);
    s.setY(p2);
    return in;
}


////////////////////////


SquareAssociated::SquareAssociated(){
    this->color = Color::BLACK;
}


///////////////////////////////////

SquareAggregated::SquareAggregated(){
    this->x = NULL;
    this->y = NULL;
    this->color = Color::BLACK;
}
SquareAggregated::SquareAggregated(Point *x, Point *y, Color col) {
    this->x = new Point(x->getX(),x->getY());
    this->y = new Point(x->getX(),x->getY());
    this->color = col;
}
SquareAggregated::SquareAggregated(int a,int b,int c,int d, Color col) {
    this->x = new Point(a,b);
    this->y = new Point(c,d);
    this->color = col;
}

Point* SquareAggregated::getX() {
    return this->x;
}
Point* SquareAggregated::getY() {
    return this->y;
}
void SquareAggregated::setX(Point *x) {
    this->x = x;
}
void SquareAggregated::setY(Point *y) {
    this->y = y;
}

void SquareAggregated::draw() {
    if (this->getX() != NULL && this->getY() != NULL) {
        setcolor(static_cast<int>(this->color));
        line(this->getX()->getX(),this->getX()->getY(),this->getX()->getX(),this->getY()->getY());//Top Line
        line(this->getX()->getX(),this->getX()->getY(),this->getY()->getX(),this->getX()->getY());//Left Line
        line(this->getY()->getX(),this->getY()->getY(),this->getY()->getX(),this->getX()->getY());//Bottom Line
        line(this->getY()->getX(),this->getY()->getY(),this->getX()->getX(),this->getY()->getY());//Right Line
    }

}

ostream & operator << (ostream &out, const SquareAggregated &s)
{
    out<<"Square Aggregated--------"<<endl;
    out<<"Point 1 : "<<*(s.x);
    out<<"Point 2 : "<<*(s.y);
    return out;
}

istream & operator >> (istream &in,  SquareAggregated &s)
{
    Point p1,p2;
    cout << "Enter First Point: "<<endl;
    in >> p1;
    cout << "Enter Second Point: "<<endl;
    in >> p2;
    s.setX(&p1);
    s.setY(&p2);
    return in;
}
