#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;
/*
Challenges:
1. Given an circular list, implement an algorithm wich returns node at the
beginning of the loop.
*/

struct Node {
    char data;
    Node *next;
    Node() : data('\0'), next(nullptr) {}
    Node(char data): data(data), next(nullptr) {}
    Node(char data, Node *next): data(data), next(next) {}
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int countNodes();
    public:
        LinkedList();
        Node* getHead();
        Node* getTail();
        void insertNode(char data);
        void printCircularLinkedList(Node* node);
        Node* detectLoopNode();
        Node* getRandomMiddleNode(int n);
        ~LinkedList();
};

Node * LinkedList::getHead() {
    return this->head;
}

Node * LinkedList::getTail() {
    return this->tail;
}

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::insertNode(char data) {
    Node *end = new Node(data);

    if(this->head == nullptr) {
        this->head = end;
        this->tail = head;
    }
    else {
        this->tail->next = end;
        this->tail = this->tail->next;
    }
}

void LinkedList::printCircularLinkedList(Node* node) {

    Node *aux = this->head;
    bool loop = false;

    while(aux != NULL) {
        cout << aux->data << " ";

        if(node == aux and !loop) {
            loop = true;
        }
        else if(node == aux) {
            break;
        }

        aux = aux->next;
    }

    cout << endl;
}

Node* LinkedList::detectLoopNode() {
    set<Node*> nodes;

    Node *tmp = this->head;

    nodes.insert(tmp);

    while(tmp) {
        tmp = tmp->next;

        if(nodes.count(tmp)) {
            break;
        }

        nodes.insert(tmp);
    }

    return tmp;
}

Node * LinkedList::getRandomMiddleNode(int n) {
    if(n < 3) return nullptr;

    srand(time(NULL));
    int randomSteps = rand() % (n-2) + 2;

    Node *aux = this->head;

    for (int i = 1; i < randomSteps; i++) {
        aux = aux->next;
    }

    return aux;
}

LinkedList::~LinkedList() {
    Node *temp = nullptr;

    while (this->head != nullptr) {
        temp = this->head;
        this->head = this->head->next;

        if(temp == this->tail) {
            delete this->tail;
            break;
        }

        if(temp != nullptr) {
            delete temp;
            temp = nullptr;
        }
    }
}

int main() {
    char data;
    int n;
    LinkedList ll;
    cout << "Type num of nodes: ";
    cin >> n;
    cout << "Type values for nodes:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> data;
        ll.insertNode(data);
    }

    Node* tail = ll.getTail();
    // Turn the single list into a circular list
    tail->next = ll.getRandomMiddleNode(n);

    Node* loopNode = ll.detectLoopNode();
    cout << loopNode->data << ", dir: " << loopNode << endl;
    ll.printCircularLinkedList(loopNode);

    return 0;
}
