#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
using namespace std;
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

#endif // POINT_H_INCLUDED
