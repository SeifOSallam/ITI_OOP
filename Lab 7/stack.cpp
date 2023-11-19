#include <iostream>

using namespace std;

template <typename T>
class Stack {
    T* arr;
    int top;
    int arrSize;
public:
    Stack() {
        arr = new T[5];
        arrSize = 5;
        top = -1;
    }
    Stack(int arrsz) {
        arr = new T[arrsz];
        this->arrSize = arrsz;
        top = -1;
    }
    Stack(Stack& s) {
        arrSize = s.arrSize;
        top = s.top;
        arr = new T[arrSize];
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
    void push(T x) {
        if (top != arrSize - 1){
            arr[++top] = x;
        }
        else {
            this->Extend();
            arr[++top] = x;
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
    void Extend() {
        T *tempArr = new T[arrSize*2];
        for (int i=0;i<arrSize;i++) {
            tempArr[i] = arr[i];
        }
        delete[] arr;
        arr = tempArr;
        arrSize*=2;
    }
    ~Stack(){
        delete[] arr;
    }
};



int main(){
    Stack<int> myStack(3);
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.print();
}
