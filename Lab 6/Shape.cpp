#include <iostream>
#include "Classes.h"
#include "Shape.h"
using namespace std;
void Shape::setClr(Color x) {
    this->color = x;
}
Color Shape::getColor() {
    return color;
}
void Shape::draw(){}
ostream & operator << (ostream &out, const Shape &s)
{
    dynamic_cast<SquareComposite*>ptr
    if ( != NULL) {
        out<<;
    }
    return out;
}
