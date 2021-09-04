#include <bits/stdc++.h>

using namespace std;

/*
Write a program to sort a stack in ascending order. You should not make any
assumptions about how the stack is implemented.
The following are the only functions that should be used to write this program:
push | pop | peek | isEmpty.
*/

class MyStack {
    private:
        stack<int> s1;
        stack<int> buffer;
    public:
        MyStack();
        void push(int val);
        void pop();
        int peek();
        bool isEmpty();
        ~MyStack();
};

MyStack::MyStack() {
}

void MyStack::push(int val) {

    while(!this->s1.empty() and val > this->s1.top()) {
        this->buffer.push(this->s1.top());
        this->s1.pop();
    }
    this->s1.push(val);

    while(!this->buffer.empty()) {
        this->s1.push(this->buffer.top());
        this->buffer.pop();
    }
}

void MyStack::pop() {
    this->s1.pop();
}

int MyStack::peek() {
    return this->s1.top();
}

bool MyStack::isEmpty() {
    return this->s1.empty();
}

MyStack::~MyStack() {
    while(!this->s1.empty()) {
        this->s1.pop();
    }
}

int main() {
    MyStack stack;
    int n, val;
    cout << "Type n: ";
    cin >> n;

    cout << "Type the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        stack.push(val);
    }

    while(!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
}
