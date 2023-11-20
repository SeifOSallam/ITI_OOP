#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include "Point.h"
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

class Shape{
protected:
    Color color;
public:
    void setClr(Color x);
    Color getColor();
    virtual void draw();
    friend ostream & operator << (ostream &out, const Shape *s);
};

#endif // SHAPE_H_INCLUDED
