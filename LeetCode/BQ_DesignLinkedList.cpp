#include <bits/stdc++.h>
// https://leetcode.com/problems/design-linked-list/
// Tag(s): data structures
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

struct Node {
    int val;
    Node *next;
    Node(): val(0), next(nullptr) {}
    Node(int val): val(val), next(
        nullptr) {}
    Node(int val, Node *next): val(val), next(next) {}
};

class MyLinkedList {
private:
    Node *head;
    Node *tail;
    int n;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head = new Node();
        this->tail = this->head;
        this->n = 0;
    }

    void printList() {
        Node *tmp = this->head;

        while(tmp != nullptr) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= this->n) return -1;

        Node *tmp = this->head;
        int cont = 0;

        while(tmp != nullptr and cont < index) {
            tmp = tmp->next;
            ++cont;
        }

        return tmp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(this->head == this->tail and this->n == 0) {
            this->head->val = val;
        }
        else {
            Node *tmp = this->head;
            this->head = new Node(val);
            this->head->next = tmp;
        }
        this->n++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(this->head == this->tail and this->n == 0) {
            this->tail->val = val;
        }
        else {
            Node *tmp = this->tail;
            this->tail = new Node(val);
            tmp->next = this->tail;
        }
        this->n++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > this->n) return;

        if(index == this->n) return this->addAtTail(val);
        else if(index == 0) return this->addAtHead(val);

        Node *tmp = this->head;
        Node *prev = tmp;
        int cont = 0;

        while(tmp != nullptr and cont < index) {
            ++cont;
            prev = tmp;
            tmp = tmp->next;
        }

        if(prev != nullptr) {
            Node* current = new Node(val);
            prev->next = current;
            current->next = tmp;
        }
        this->n++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= this->n) return;

        Node *tmp = this->head;
        Node *prev;
        int cont = 0;

        while(tmp != nullptr and cont < index) {
            prev = tmp;
            tmp = tmp->next;
            ++cont;
        }

        if(this->head == this->tail) {
            this->head->val = 0;
        }
        else if(tmp == this->tail) {

            this->tail = prev;
            prev = prev->next;
            this->tail->next = nullptr;

            free(prev);
        }
        else if(index == 0) {
            tmp = this->head;
            this->head = this->head->next;

            free(tmp);
        }
        else if(tmp != nullptr) {
            prev->next = tmp->next;

            free(tmp);
        }
        this->n--;
    }
};

int main() {
    MyLinkedList linkedList;

    linkedList.addAtHead(1);
    linkedList.printList();

    linkedList.addAtTail(3);
    linkedList.printList();

    linkedList.addAtIndex(1, 2);
    linkedList.printList();

    cout << linkedList.get(1) << endl;

    linkedList.deleteAtIndex(1);
    linkedList.printList();

    cout << linkedList.get(1) << endl;

    return 0;
}
