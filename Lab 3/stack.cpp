#include <iostream>

using namespace std;

class Stack{
    int* arr;
    int top;
    int arrSize;
public:
    Stack() {
        arr = new int[10]{0};
        arrSize = 10;
        top = -1;
    }
    Stack(int arrsz) {
        arr = new int[arrsz]{0};
        this->arrSize = arrsz;
        top = -1;
    }
    Stack(Stack& s) {
        arrSize = s.arrSize;
        top = s.top;
        arr = new int[arrSize];
        for (int i=0;i<=top;i++) {
            arr[i] = s.arr[i];
        }
    }
    void print() {
        for (int i=0;i<=top;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void push(int x) {
        if (top != arrSize - 1){
            arr[++top] = x;
        }
        else {
            cout<<"Array is full, please pop a number."<<endl;
        }
    }
    void pop() {
        if (top != -1){
            top--;
        }
        else {
            cout<<"Array is empty, please insert(push) a number."<<endl;
        }
    }
    void emptyStack() {
        top = -1;
    }
    ~Stack(){
        delete[] arr;
    }
};

int main(){
    Stack s;
    s.push(3);
    s.push(5);
    s.push(7);
    s.print();
    s.pop();
    s.print();
    s.push(10);
    s.push(20);
    s.print();
    cout<<"------------"<<endl;
    Stack s2 = s;
    s2.print();
    s.pop();
    s.pop();
    s2.print();
    s.print();
    s2.pop();
    s2.print();
}
