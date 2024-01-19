#include <bits/stdc++.h>
// solved
// tags: linked-list, implementation
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


LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) {
    /*My solution:
    Time: O(n)
    Space: O(1)
    */
    int lastValue = linkedList->value;
    LinkedList* lastNode = linkedList;
    LinkedList* head = linkedList;

    linkedList = linkedList->next;

    while(linkedList != nullptr) {
        if(lastValue != linkedList->value) {
            lastValue = linkedList->value;

            if(lastNode->next != linkedList) lastNode->next = linkedList;

            lastNode = linkedList;
        }
        else if(linkedList->next == nullptr and lastValue == linkedList->value) {
            lastNode->next = nullptr;
        }

        linkedList = linkedList->next;
    }

    return head;
}

LinkedList* removeDuplicatesFromLinkedList2(LinkedList* linkedList) {
    /*My solution 2:
    Time: O(n)
    Space: O(1)
    */
    LinkedList* head = linkedList;

    while(linkedList != nullptr) {
        if(linkedList->next != nullptr and linkedList->next->value == linkedList->value) {
            linkedList->next = linkedList->next->next;
        }
        else linkedList = linkedList->next;
    }

    return head;
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

    auto primed = removeDuplicatesFromLinkedList2(list);

    printLinkedList(primed);

	return 0;
}
