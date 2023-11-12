#include <iostream>

using namespace std;

class Queue{
    int* arr;
    int arrSize;
    int frontP;
    int rearP;
    int currSize;
public:
    Queue() {
        arr = new int[10]{0};
        arrSize = 10;
        frontP = 0;
        rearP = 0;
        currSize = 0;
    }
    Queue(int arrsz) {
        arr = new int[arrsz]{0};
        this->arrSize = arrsz;
        frontP = 0;
        rearP = 0;
        currSize = 0;
    }
    void push(int x) {
        if (currSize != arrSize) {
            arr[frontP++] = x;
            if (frontP == arrSize) {
                frontP = 0;
            }
            currSize++;
        }
        else {
            cout<<"Array is full, please pop a number."<<endl;
        }
    }
    void pop() {
        if (currSize != 0) {
            rearP++;
            if (rearP == arrSize) {
                rearP = 0;
            }
            currSize--;
        }
        else {
            cout<<"Array is full, please insert a number."<<endl;
        }
    }
    void print() {
        int x = rearP;
        for (int i=0;i<currSize;i++) {
            cout<<arr[x++]<<" ";
            if (x == arrSize) {
                x = 0;
            }
        }
        cout<<endl;
    }
    ~Queue() {
        delete[] arr;
    }
};

int main(){
    Queue q(5);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(10);
    q.push(7);
    q.print();
    q.pop();
    q.print();
    q.push(20);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
}
