#include <bits/stdc++.h>
// https://app.codesignal.com/interview-practice/task/6rE3maCQwrZS3Mm2H/description
// Tag(s): Data structures, linked list
using namespace std;

// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    ListNode<int> *ans = nullptr;
    ListNode<int> *tmp = nullptr;

    while(l1 and l2) {
        ListNode<int> *aux;
        if(l1->value < l2->value) {
            aux = new ListNode<int>(l1->value);
            l1 = l1->next;
        }
        else {
            aux = new ListNode<int>(l2->value);
            l2 = l2->next;
        }

        if(ans != nullptr) {
            tmp->next = aux;
        }
        else {
            ans = aux;
        }
        tmp = aux;
    }

    while(l1) {
        ListNode<int> *aux = new ListNode<int>(l1->value);

        if(ans != nullptr) tmp->next = aux;
        else ans = aux;

        tmp = aux;
        l1 = l1->next;
    }

    while(l2) {
        ListNode<int> *aux = new ListNode<int>(l2->value);

        if(ans != nullptr) tmp->next = aux;
        else ans = aux;

        tmp = aux;
        l2 = l2->next;
    }

    return ans;
}

int main() {

    return 0;
}
