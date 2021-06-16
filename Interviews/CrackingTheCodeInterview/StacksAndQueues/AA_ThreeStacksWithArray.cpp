#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int data;
    Item * previous;

    Item() : data(0), previous(nullptr) {}
    Item(int data) : data(data), previous(nullptr) {}
    Item(int data, Item* previous): data(data), previous(previous) {}
};

class TriStack {
    private:
        vector<Item*> hub;
    public:
        TriStack();
        void pushS1(int data);
        void pushS2(int data);
        void pushS3(int data);
        Item* getTopS1();
        Item* getTopS2();
        Item* getTopS3();
        void popS1();
        void popS2();
        void popS3();
        bool isEmptyS1();
        bool isEmptyS2();
        bool isEmptyS3();
        ~TriStack();
};

TriStack::TriStack() {
    for (int i = 0; i < 3; i++) {
        this->hub.push_back(nullptr);
    }
}

void TriStack::pushS1(int data) {
    if(this->isEmptyS1()) {
        this->hub[0] = new Item(data, nullptr);
    }
    else {
        Item *item = new Item(data, this->hub.at(0));
        this->hub[0] = item;
    }
}

void TriStack::pushS2(int data) {
    if(this->isEmptyS2()) {
        this->hub[1] = new Item(data, nullptr);
    }
    else {
        Item *item = new Item(data, this->hub.at(1));
        this->hub[1] = item;
    }
}

void TriStack::pushS3(int data) {
    if(this->isEmptyS3()) {
        this->hub[2] = new Item(data, nullptr);
    }
    else {
        Item *item = new Item(data, this->hub.at(2));
        this->hub[2] = item;
    }
}

Item* TriStack::getTopS1() {
    return this->hub.at(0);
}

Item* TriStack::getTopS2() {
    return this->hub.at(1);
}

Item* TriStack::getTopS3() {
    return this->hub.at(2);
}

void TriStack::popS1() {
    if(this->isEmptyS1()) {
        return;
    }

    Item *tmp = this->hub[0];
    this->hub[0] = this->hub[0]->previous;

    delete tmp;
    tmp = nullptr;
}

void TriStack::popS2() {
    if(this->isEmptyS2()) {
        return;
    }

    Item *tmp = this->hub[1];
    this->hub[1] = this->hub[1]->previous;

    delete tmp;
    tmp = nullptr;
}

void TriStack::popS3() {
    if(this->isEmptyS3()) {
        return;
    }

    Item *tmp = this->hub[2];
    this->hub[2] = this->hub[2]->previous;

    delete tmp;
    tmp = nullptr;
}

bool TriStack::isEmptyS1() {
    return this->hub.at(0) == nullptr or this->hub.at(0) == NULL;
}

bool TriStack::isEmptyS2() {
    return this->hub.at(1) == nullptr or this->hub.at(1) == NULL;
}

bool TriStack::isEmptyS3() {
    return this->hub.at(2) == nullptr or this->hub.at(2) == NULL;
}

TriStack::~TriStack() {
    for (int i = 0; i < 3; i++) {
        Item *tmp = this->hub[i];

        while(tmp != NULL) {
            Item *aux = tmp;

            tmp = tmp->previous;

            delete aux;
            aux = nullptr;
        }
    }

    if(!this->hub.empty()) {
        this->hub.clear();
    }
}

int main() {
    int n, id, data;
    cout << "Type number of elements to insert: ";
    cin >> n;
    cout << "Type id_stack[1-3] and data to insert: " << endl;

    TriStack tri;

    for (int i = 0; i < n; i++) {
        cin >> id >> data;
        if(id == 1) {
            tri.pushS1(data);
        }
        else if(id == 2) {
            tri.pushS2(data);
        }
        else if(id == 3) {
            tri.pushS3(data);
        }
    }

    // Printing the stacks

    // Printing the stack 1
    while(!tri.isEmptyS1()) {
        Item *item = tri.getTopS1();
        if(item != nullptr) {
            cout << item->data << "->";
            tri.popS1();
        }
    }
    cout << endl;
    // Printing the stack 2
    while(!tri.isEmptyS2()) {
        Item *item = tri.getTopS2();
        if(item != nullptr) {
            cout << item->data << "->";
            tri.popS2();
        }
    }
    cout << endl;
    // Printing the stack 3
    while(!tri.isEmptyS3()) {
        Item *item = tri.getTopS3();
        if(item != nullptr) {
            cout << item->data << "->";
            tri.popS3();
        }
    }

    return 0;
}
