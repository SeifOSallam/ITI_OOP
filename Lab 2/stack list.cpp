#include <iostream>

using namespace std;

template <typename T> struct Block {
    T data;
    Block* next;
};

template <typename T> class Stack {
    Block<T>* head;
public:
    Stack() {
        head = NULL;
    }
    Stack(T data) {
        head = new Block<T>;
        head->data = data;
        head->next = NULL;
    }
    void push(T data) {
        if (head == NULL) {
            head = new Block<T>;
            head->data = data;
            head->next = NULL;
        }
        else {
            Block<T>* currBlock = head;
            while (currBlock->next != NULL) {
                currBlock = currBlock->next;
            }
            currBlock->next = new Block<T>;
            currBlock->next->data = data;
            currBlock->next->next = NULL;
        }
    }
    void pop() {
        if (head->next != NULL) {
            Block<T>* currBlock = head;
            Block<T>* prevBlock;
            while (currBlock->next != NULL) {
                prevBlock=currBlock;
                currBlock = currBlock->next;
            }
            delete currBlock;
            prevBlock->next = NULL;
        }
        else {
            head = NULL;
        }

    }
    void print() {
        if (head != NULL) {
            Block<T>* currBlock = head;
            while (currBlock != NULL) {
                cout<<currBlock->data<<"  ";
                currBlock = currBlock->next;
            }
            cout<<endl;
        }
        else cout<<"Stack is empty"<<endl;0
    }

    ~Stack() {
        Block<T>* X = head;
        head = head->next;
        delete X;
    }

};




int main(){
    Stack<int> myStack;
    /*myStack.push(6);
    myStack.push(3);
    myStack.push(7);
    myStack.print();
    myStack.pop();
    myStack.print();
    myStack.push(10);
    myStack.push(11);
    myStack.print();*/
    myStack.push(3);
    myStack.pop();
    myStack.print();
    myStack.push(3);
    myStack.push(3);
    myStack.print();
}
