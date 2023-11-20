#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include "graphics.h"
#include "Classes.h"

using namespace std;

int main()
{
    initwindow(800, 800);
    vector<Shape*> shapes;

    shapes.push_back(new SquareComposite(100,150,300,350, Color::YELLOW));


    while(true) {
        cleardevice();
        for (int i=0;i<shapes.size();i++) {
            shapes[i]->draw();
        }
        system("cls");
        cout<<"1- Insert Square"<<endl;
        cout<<"2- Insert Circle"<<endl;
        cout<<"3- Insert Line"<<endl;
        cout<<"4- Print All"<<endl;
        cout<<"5- Clear All"<<endl;
        cout<<"6- Exit"<<endl;
        char c = _getch();
        switch(c) {
            case '1': {
                system("cls");
                cout<<"Enter the color:"<<endl;
                int x;
                cin>>x;
                Color val = static_cast<Color>(x);
                Point p1,p2;
                cout<<"P1:"<<endl;
                cin>>p1;
                cout<<endl;
                cout<<"P2:"<<endl;
                cin>>p2;
                shapes.push_back(new SquareComposite(p1,p2,val));
                break;
            }
            case '2': {
                system("cls");
                cout<<"Enter the color:"<<endl;
                int x;
                cin>>x;
                Color val = static_cast<Color>(x);
                int radius;
                cout<<"Enter the radius: ";
                cin>>radius;
                Point p1;
                cout<<"P:"<<endl;
                cin>>p1;
                shapes.push_back(new CircleComposite(p1,radius,val));
                break;
            }
            case '3': {
                system("cls");
                cout<<"Enter the color:"<<endl;
                int x;
                cin>>x;
                Color val = static_cast<Color>(x);
                Point p1,p2;
                cout<<"P1:"<<endl;
                cin>>p1;
                cout<<endl;
                cout<<"P2:"<<endl;
                cin>>p2;
                shapes.push_back(new Lne(p1,p2,val));
                break;
            }
            case '4': {
                system("cls");
                for (int i=0;i<shapes.size();i++) {
                    cout<<*(shapes[i]);
                }
                SquareComposite s(50,80,130,150,Color::RED);
                cout<<s;
                SquareAggregated t(50,80,130,150,Color::RED);
                cout<<t;
                CircleComposite cp(50,30,130,Color::RED);
                cout<<cp;
                Lne l(50,80,150,200,Color::RED);
                cout<<l<<endl;
                cout<<endl<<"Press Any Key to Continue...";
                _getch();
                break;
            }
            case '5': {
                shapes.clear();
                break;
            }
            case '6': {
                return 0;
            }
            default: break;
        }

    }
    closegraph();
}
