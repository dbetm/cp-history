#include <bits/stdc++.h>
// https://app.codesignal.com/interview-practice/task/gX7NXPBrYThXZuanm/description
// Tag(s): Linked Lists, data structures
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    ListNode<int> *tmp = l;
    ListNode<int> *past = nullptr;

    while(tmp != nullptr) {
        bool deleted = false;
        ListNode<int> *x = tmp;
        if(tmp->value == k) {
            deleted = true;
            if(past == nullptr) { // head of the list
                l = tmp->next;
            }
            else {
                past->next = tmp->next;
            }
        }
        else past = tmp;
        tmp = tmp->next;
        if(deleted) delete(x);
    }

    return l;
}

void printLinkedList(ListNode<int> *l) {
    ListNode<int> *tmp = l;

    while(tmp != nullptr) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    int n, val, k;
    cin >> n;

    cin >> val;
    ListNode<int> *l = new ListNode<int>(val);
    ListNode<int> *tmp = l;
    --n;

    while(n--) {
        cin >> val;
        ListNode<int> *aux = new ListNode<int>(val);
        tmp->next = aux;
        tmp = aux;
    }
    cin >> k;

    ListNode<int> *ans = removeKFromList(l,k);

    printLinkedList(ans);

    return 0;

}
