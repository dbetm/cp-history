#include <bits/stdc++.h>
// solved
// tags: pointers, data structures, linked-list, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;

// This is an input struct. Do not edit.
class LinkedList {
    public:
        int value;
        LinkedList* next = nullptr;

        LinkedList(int value) { this->value = value; }

        LinkedList* insert(int value) {
            this->next = new LinkedList(value);

            return this->next;
        }
};

void printLinkedList(LinkedList* list) {
    while(list != nullptr) {
        cout << list->value << " ";
        list = list->next;
    }

    cout << endl;
}


LinkedList* middleNode(LinkedList* linkedList) {
    /*My solution:
    Time: O(n)
    Space: O(1)
    */
    LinkedList* node = linkedList;
    int count = 0;

    while(node != nullptr) {
        count += 1;
        node = node->next;
    }

    int middle = count / 2;
    node = linkedList;

    count = 0;

    while(node != nullptr) {
        if(count == middle) break;
        count += 1;
        node = node->next;
    }

    return node;
}

LinkedList* middleNode2(LinkedList* linkedList) {
    /*Proposal:
    Time: O(n)
    Space: O(1)
    */
    LinkedList* node = linkedList;
    LinkedList* node2x = node->next;

    while(node2x != nullptr) {
        node = node->next;
        node2x = (node2x->next == nullptr)? node2x->next: node2x->next->next;
    }

    return node;
}


int main() {
    int n;

    cin >> n;

    int headValue;
    int val;

    cin >> headValue;
    LinkedList* list = new LinkedList(headValue);
    auto tmp = list;
    n--;

    while(n--) {
        cin >> val;
        tmp = tmp->insert(val);
    }

    printLinkedList(list);

    auto middle = middleNode(list);

    printLinkedList(middle);

    middle = middleNode2(list);
    printLinkedList(middle);

	return 0;
}
