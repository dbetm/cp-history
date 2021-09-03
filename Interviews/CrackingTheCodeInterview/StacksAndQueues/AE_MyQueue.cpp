#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " es " << x << endl;
/*
Implement a MyQueue class which implements a queue using two stacks.
The operations of a queue are: empty, size, front, back, push_back, pop_front.
*/
class MyQueue {
    private:
        stack<int> A; // A keeps an inverse order relative to the queue
        stack<int> B; // B keeps a natural order relative to the queue
    public:
        MyQueue();
        bool empty();
        int size();
        int front();
        int back();
        void push_back(int val);
        void pop_front();
        ~MyQueue();
};

MyQueue::MyQueue() {
}

bool MyQueue::empty() {
    return (this->A.empty() and this->B.empty());
}

int MyQueue::size() {
    return (this->A.size() + this->B.size());
}

int MyQueue::front() {
    int front;

    if(this->A.empty()) {
        // front is the top element in B
        front = this->B.top();
    }
    else {
        // front is the last element in A
        while(!this->A.empty()) {
            this->B.push(this->A.top());
            this->A.pop();
        }
        front = this->B.top();
    }

    return front;
}

int MyQueue::back() {
    int back;

    if(this->A.empty()) {
        while(!this->B.empty()) {
            this->A.push(this->B.top());
            this->B.pop();
        }
        back = this->A.top();
    }
    else {
        back = this->A.top();
    }

    return back;
}

void MyQueue::push_back(int val) {
    if(this->A.empty()) {
        while(!this->B.empty()) {
            this->A.push(this->B.top());
            this->B.pop();
        }
    }

    this->A.push(val);
}

void MyQueue::pop_front() {
    if(this->A.empty()) {
        this->B.pop();
    }
    else {
        while(!this->A.empty()) {
            this->B.push(this->A.top());
            this->A.pop();
        }
        this->B.pop();
    }
}

MyQueue::~MyQueue() {
    while(!this->A.empty()) {
        this->A.pop();
    }

    while(!this->B.empty()) {
        this->B.pop();
    }
}

int main() {
    string menu = "{1: empty, 2: size, 3: front, 4: back, 5: push_back, 6: pop_front}";

    int ops, operation, number;
    cout << "Type the num of ops: ";
    cin >> ops;

    MyQueue myqueue;

    for (int i = 0; i < ops; ++i) {
        cout << "Type the op " << menu << ": " << endl;
        cin >> operation;

        switch (operation) {
            case 1:
                cout << "is empty? " << myqueue.empty() << endl;
                break;
            case 2:
                cout << "Size: " << myqueue.size() << endl;
                break;
            case 3:
                cout << "Front: " << myqueue.front() << endl;
                break;
            case 4:
                cout << "Back: " << myqueue.back() << endl;
                break;
            case 5:
                cout << "Type the number to push back: ";
                cin >> number;
                myqueue.push_back(number);
                break;
            case 6:
                cout << "Pop front" << endl;
                myqueue.pop_front();
                break;
            default:
                cout << "Not allowed" << endl;
        }
    }

    return 0;
}
