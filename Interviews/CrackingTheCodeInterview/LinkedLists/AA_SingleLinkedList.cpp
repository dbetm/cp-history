#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;
/*
Challenges:
1. Remove duplicates from a unsorted linked list (a temporary buffer is not
allowed).
2. Find the nth to last element.
3. Deleting a node in the middle of a single linked list, given only access to
that node.
4. Sum two numbers that are stored in two linked list in reverse order, the
result must be stored in a linked list.
INPUT: (3->1->5) + (5->9->2)
RESULT: (8->0->8).
*/

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int countNodes();
    public:
        LinkedList();
        Node* getHead();
        void insertNode(int data);
        void removeDuplicates();
        void printLinkedList();
        Node* findElement(int data);
        Node* nthToLast(int n);
        void deleteMiddleNode(Node *node);
        bool isEmpty();
        Node* getRandomMiddleNode();
        ~LinkedList();
};
// FUNCTIONS
void sumTwoNumbers(LinkedList *lla, LinkedList *llb, LinkedList *result) {

    Node *a = lla->getHead();
    Node *b = llb->getHead();

    int carry = 0, res;
    while(a and b) {
        res = a->data + b->data + carry;
        carry = res / 10;
        res = res % 10;
        result->insertNode(res);

        a = a->next;
        b = b->next;
    }

    while(a) {
        res = a->data + carry;
        carry = res / 10;
        res = res % 10;
        result->insertNode(res);

        a = a->next;
    }

    while(b) {
        res = b->data + carry;
        carry = res / 10;
        res = res % 10;
        result->insertNode(res);

        b = b->next;
    }

    if(carry > 0) result->insertNode(carry);
}


// METHODS OF LINKED LIST

Node * LinkedList::getHead() {
    return this->head;
}

int LinkedList::countNodes() {
    int count = 0;
    Node *aux = this->head;

    while(aux) {
        count++;
        aux = aux->next;
    }

    return count;
}

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::insertNode(int data) {
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

void LinkedList::removeDuplicates() {
    Node *pivote = this->head;
    while(pivote) {
        Node *cursor = pivote->next;
        Node *precursor = pivote;
        while(cursor) {
            if(cursor->data == pivote->data) {
                Node *temp = cursor;
                precursor->next = cursor->next;
                cursor = cursor->next;
                delete temp;
                continue;
            }
            precursor = cursor;
            cursor = cursor->next;
        }
        pivote = pivote->next;
    }
}

void LinkedList::printLinkedList() {
    Node *aux = this->head;
    while(aux != NULL) {
        cout << aux->data << " ";
        aux = aux->next;
    }

    cout << endl;
}

Node * LinkedList::findElement(int data) {
    Node *temp = head;
    while(temp) {
        if(temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

Node * LinkedList::nthToLast(int n) {
    if(this->head == NULL or n < 1) return nullptr;

    Node *p1 = this->head;
    Node *p2 = this->head;

    for (int i = 0; i < n-1; ++i) { // skip n-1 steps ahead
        if(p2 == NULL) {
            return nullptr; // not found since list size < n
        }
        p2 = p2->next;
    }
    while(p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

void LinkedList::deleteMiddleNode(Node *node) {
    Node *aux = this->head;
    while(aux->next) {
        if(aux->next == node) {
            Node *tmp = node;
            aux->next = node->next;
            delete tmp;
            break;
        }
        aux = aux->next;
    }
}

bool LinkedList::isEmpty() {
    return this->head == nullptr;
}

Node * LinkedList::getRandomMiddleNode() {
    int numNodes = this->countNodes();
    if(numNodes < 3) return nullptr;

    srand(time(NULL));
    int randomSteps = rand() % (numNodes-2) + 2;

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

        if(temp != nullptr) {
            delete temp;
            temp = nullptr;
        }
    }
}

int main() {
    /*
    int n, data;
    LinkedList ll;
    cout << "Type num of nodes: ";
    cin >> n;
    cout << "Type values for nodes" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        ll.insertNode(data);
    }
    */

    /*
    ll.printLinkedList();
    ll.removeDuplicates();
    ll.printLinkedList();
    */

    /*
    cout << "Type data to search: ";
    cin >> data;
    Node *ans = ll.findElement(data);
    if(ans != nullptr) cout << ans << endl;
    else cout << "NOT FOUND" << endl;
    */

    /*
    cout << "Type N to search nth element from last one: ";
    cin >> n;
    Node *ans = ll.nthToLast(n);
    if(ans != nullptr) {
        cout << ans << " --->  " << ans->data << endl;
    }
    else cout << "NOT FOUND" << endl;
    */

    /*
    ll.printLinkedList();
    Node *ans3 = ll.getRandomMiddleNode();
    cout << "Random node to delete: " << ans3->data << endl;
    ll.deleteMiddleNode(ans3);
    ll.printLinkedList();
    */

    // 4. SUM TWO NUMBERS
    int data, n;
    // First number
    LinkedList lla;
    cout << "Type num of nodes for list A: ";
    cin >> n;
    cout << "Type values for nodes for list A" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        lla.insertNode(data);
    }
    // Second number
    LinkedList llb;
    cout << "Type num of nodes for list B: ";
    cin >> n;
    cout << "Type values for nodes for list B" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        llb.insertNode(data);
    }

    // Compute the result
    LinkedList result;
    sumTwoNumbers(&lla, &llb, &result);
    cout << "RESULT:" << endl;
    result.printLinkedList();

    return 0;
}
