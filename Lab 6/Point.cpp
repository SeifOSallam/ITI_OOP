#include <iostream>
#include "Classes.h"

using namespace std;
Point::Point(){
    this->x = 100;
    this->y = 100;
}

Point::Point(int x,int y) {
    this->x = x;
    this->y = y;
}
void Point::setX(int x){
    this->x = x;
}
void Point::setY(int y){
    this->y = y;
}
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
ostream & operator << (ostream &out, const Point &p)
{
    out<<"("<<p.x<<", "<<p.y<<")"<<endl;
    return out;
}

istream & operator >> (istream &in,  Point &p)
{
    cout << "Enter X: ";
    in >> p.x;
    cout << "Enter Y: ";
    in >> p.y;
    return in;
}
