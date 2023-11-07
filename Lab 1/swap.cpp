#include <iostream>

using namespace std;

void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    cout<<"In function:"<<endl;
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;
}

void swapByReference(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void swapByAddress(int &x, int &y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

int main() {
    int x = 5, y = 10;
    swapByValue(x, y);
    cout<<"Values after swap by value:"<<endl;
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;

    swapByReference(&x, &y);
    cout<<"Values after swap by reference:"<<endl;
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;

    swapByAddress(x, y);
    cout<<"Values after swap by reference:"<<endl;
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;
}
