#include <iostream>
#include "graphics.h"

using namespace std;

int i, j = 0, gd = DETECT, gm;

const int Width = 800;
const int Height = 600;
int g_offSet = 200;
typedef int Radius;

struct Point
{
    double x;
    double y;
    Point() {}
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
    void setXY(double a, double b) {
        x = a;
        y = b;
    }
};///////

class Lne {
    Point p1;
    Point p2;
public:
    Lne():p1(10,10),p2(50,10) {}
    Lne(Point p1, Point p2) {
        this->p1 = p1;
        this->p2 = p2;
    }
    Lne(double a, double b, double c, double d) {
        p1.setXY(a,b);
        p2.setXY(c,d);
    }
    void drawLine() {
        line(p1.x, p1.y, p2.x, p2.y);

    }
};
class LneAggr {
    Point* p1;
    Point* p2;
public:
    LneAggr(){p1 = NULL; p2 = NULL;}
    LneAggr(Point* p1, Point* p2) {
        this->p1 = p1;
        this->p2 = p2;
    }
    LneAggr(double a, double b, double c, double d) {
        p1 = new Point(a,b);
        p2 = new Point(c,d);
    }
    void drawLine() {
        if (p1 != NULL && p2 != NULL)
            line(p1->x, p1->y, p2->x, p2->y);
        else {
            cout<<"LINE IS INCOMPLETE, ERROR"<<endl;
        }

    }
};
class LneAssc {
public:
    void drawLine(Point p1, Point p2) {
        line(p1.x, p1.y, p2.x, p2.y);
    }
};
class CrcleComp {
    Point p;
    int radius;
public:
    CrcleComp():p(10,10) {
        radius = 20;
    }
    CrcleComp(Point p, int radius) {
        this->p = p;
        this->radius = radius;
    }
    CrcleComp(double a, double b, int radius) {
        p.setXY(a,b);
        this->radius = radius;
    }
    void draw();
};
class CrcleAssc {
    int radius;
public:
    CrcleAssc(){
        radius = 20;
    }
    CrcleAssc(int radius) {
        this->radius = radius;
    }
    void draw(Point p);
};
class CrcleAggr {
    Point* p;
    int radius;
public:
    CrcleAggr(){
        p = NULL;
        radius = 20;
    }
    CrcleAggr(Point* p, int radius) {
        this->p = p;
        this->radius = radius;
    }
    CrcleAggr(CrcleAggr& c) {
        this->p = new Point(c.p->x, c.p->y);
        this->radius = c.radius;
    }
    void setPoint(Point *p) {
        this->p = p;
    }
    void setPoint(double a, double b) {
        this->p = new Point(a,b);
    }
    void copyPoint(Point* a) {
        if (a != NULL)
            this->p = new Point(a->x, a->y);
        else this->p = NULL;
    }
    bool checkNull() {
        return (p == NULL);
    }
    void shiftX(double x) {
        p->x += x;
    }
    void shiftY(double y) {
        p->y += y;
    }
    void shiftXY(double x,double y) {
        p->x += x;
        p->y += y;
    }
    void deletePoint(){
        delete p;
    }
    void draw();
};
template <typename A>
Point convertPixel(A &x, A &y)
{
    //    x+=Width/2;
    y = -y;
    y += Height - g_offSet;
    return {x, y};
}

void drawAxis()
{
    for (int i = 0; i < Height; i++)
    {
        putpixel(Width / 2, i, WHITE);
    }
    for (int i = 0; i < Width; i++)
    {
        putpixel(i, Height, WHITE);
    }
}



void drawAxis(int offSet)
{
    g_offSet = offSet;
    for (int i = 0; i < Width; i++)
    {
        putpixel(i, Height - g_offSet - 20, WHITE);
    }
}

void drawPixel(double x, double y, int color)
{
    convertPixel(x, y);
    putpixel(x, y, color);
}

void draw_line_DDA(Point a, Point b, int color)
{
    double x0 = a.x, y0 = a.y, x1 = b.x, y1 = b.y;
    double dx = x1 - x0;
    double dy = y1 - y0;

    double steps = std::max(abs(dx), abs(dy));

    double Xinc = dx / steps;
    double Yinc = dy / steps;
    for (int i = 0; i < steps; i++)
    {
        drawPixel(x0, y0, color);
        x0 += Xinc;
        y0 += Yinc;
    }
}

void draw_circle_Bressenham(Point c, Radius r, int col)
{
    double d = 3 - 2 * r;
    double y = r, x = 0;
    double h = c.x, k = c.y;

    while (y >= x)
    {
        drawPixel(h + x, k + y, col);
        drawPixel(h + y, k + x, col);
        drawPixel(h - x, k + y, col);
        drawPixel(h - y, k + x, col);
        drawPixel(h + x, k - y, col);
        drawPixel(h + y, k - x, col);
        drawPixel(h - x, k - y, col);
        drawPixel(h - y, k - x, col);
        x++;
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * x - 4 * y + 6;
            y--;
        }
    }
}

void draw_circle(Point c, Radius r, int col)
{
    convertPixel(c.x, c.y);
    int old_col = getcolor();
    setcolor(col);
    circle(c.x, c.y, r);
    setcolor(old_col);
}

void floodFill(Point currPixel, int oldcolor, int fillColor)
{
    int tempx = currPixel.x, tempy = currPixel.y;
    Point pixel = convertPixel(tempx, tempy);
    int currColor = getpixel(pixel.x, pixel.y);
    if (currColor != oldcolor)
    {
        return;
    }
    drawPixel(currPixel.x, currPixel.y, fillColor);

    floodFill(Point(currPixel.x, currPixel.y + 1), oldcolor, fillColor);
    floodFill(Point(currPixel.x, currPixel.y - 1), oldcolor, fillColor);
    floodFill(Point(currPixel.x + 1, currPixel.y), oldcolor, fillColor);
    floodFill(Point(currPixel.x - 1, currPixel.y), oldcolor, fillColor);
}



int main()
{
    initwindow(Width, Height);
    CrcleComp crcle;
    crcle.draw();
    Point p(50,50);
    CrcleAssc crcleassc;
    crcleassc.draw(p);
    Lne lne;
    lne.drawLine();


    swapbuffers();
    cleardevice();
    closegraph();
    return 0;
}

void CrcleComp::draw() {
    circle(p.x, p.y, radius);
}
void CrcleAssc::draw(Point p) {
    circle(p.x, p.y, radius);
}
void CrcleAggr::draw() {
    if (p != NULL)
        circle(p->x, p->y, radius);
    else {
        cout<<"ERROR, POINT IS NULL"<<endl;
    }
}
