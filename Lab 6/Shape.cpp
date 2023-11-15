#include <iostream>
#include "Classes.h"

using namespace std;
void Shape::setClr(Color x) {
    this->color = x;
}
Color Shape::getColor() {
    return color;
}
void Shape::draw(){}
