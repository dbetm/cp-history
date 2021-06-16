#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

/*
Design a stack with push and pop ops, also has a function
min which returns the minimum element? Push, pop and min should all operate in
O(1) time.
*/

using namespace std;

struct Item {
    int data;
    Item *prev;
    Item() : data(0), prev(nullptr) {}
    Item(int data) : data(data), prev(nullptr) {}
    Item(int data, Item *prev) : data(data), prev(nullptr) {}
};

class Stack {
    private:
        Item *min;
        Item *top;
    public:
        Stack();
        void push(int data);
        void pop();
        Item *getMin();
        void printStack();
        ~Stack();
};

Stack::Stack() {
    this->min = nullptr;
    this->top = nullptr;
}

void Stack::push(int data) {
    if(this->top == nullptr) {
        this->top = new Item(data);
        this->min = new Item(data);
    }
    else {
        Item *aux = this->top;
        this->top = new Item(data);
        this->top->prev = aux;

        if(this->min->data >= data) {
            Item *aux2 = this->min;
            this->min = new Item(data);
            this->min->prev = aux2;
        }
    }
}

void Stack::pop() {
    if(this->top == nullptr) {
        return;
    }
    else {
        Item *aux = this->top;
        this->top = this->top->prev;

        if(aux->data == this->min->data) {
            this->min = this->min->prev;
        }

        delete aux;
        aux = nullptr;
    }
}

Item *Stack::getMin() {
    return this->min;
}

void Stack::printStack() {
    Item *aux = this->top;

    while(aux != nullptr) {
        cout << aux->data << "->";
        aux = aux->prev;
    }
    cout << endl;
}

Stack::~Stack() {
    while(this->top != nullptr) {
        Item *aux = this->top;
        this->top = this->top->prev;

        delete aux;
        aux = nullptr;
    }

    while(this->min != nullptr) {
        Item *aux = this->min;
        this->min = this->min->prev;

        delete aux;
        aux = nullptr;
    }
}

int main() {
    int n, data;
    Stack s;

    cout << "Type n: ";
    cin >> n;
    cout << "Type the elements: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> data;
        s.push(data);
    }

    s.printStack();

    Item *min = s.getMin();
    cout << "Min is: " << min->data << endl;

    s.pop();
    s.pop();

    min = s.getMin();
    cout << "Min is: " << min->data << endl;

    s.printStack();

    s.pop();
    s.pop();

    min = s.getMin();
    cout << "Min is: " << min->data << endl;

    s.printStack();

    return 0;
}
