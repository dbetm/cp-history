#include <bits/stdc++.h>
// https://app.codesignal.com/interview-practice/task/XP2Wn9pwZW6hvqH67/description
// Tag(s): Linked Lists, implementation
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

void printList(ListNode<int> *l) {
    cout << "LIST" << endl;
    while(l != nullptr) {
        cout << l->value << "-";
        l = l->next;
    }
    cout << endl;
}

ListNode<int> * reverseKList(ListNode<int> *l, const int &k) {
    ListNode<int> *faster = l->next;
    l->next = nullptr;

    for (int i = 0; i < k; ++i) {
        ListNode<int> *tmp = faster->next;
        faster->next = l;
        l = faster;
        faster = tmp;
    }

    return l;
}

ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    if(l == nullptr or k == 1) return l;

    ListNode<int> *aux = nullptr;
    ListNode<int> *left = l, *right = l;
    int cont = 1;

    while(right != nullptr) {

        right = right->next;
        if(right == nullptr) break;
        cont++;

        if(cont % k == 0) {
            ListNode<int> *tmpLeft = left;
            right = right->next;

            ListNode<int> *front = reverseKList(tmpLeft, k-1);
            if(cont == k) l = front;
            else aux->next = front;

            cont++;
            aux = left;
            left = right;
        }
    }
    if(aux != nullptr) aux->next = left;

    return l;
}

int main() {
    int n, val, k;
    cin >> n;

    ListNode<int> *l = nullptr, *tmp;

    for (int i = 0; i < n; ++i) {
        cin >> val;
        if(l == nullptr) {
            l = new ListNode<int>(val);
            tmp = l;
        }
        else {
            ListNode<int> *aux = new ListNode<int>(val);
            tmp->next = aux;
            tmp = aux;
        }
    }
    cin >> k;

    ListNode<int> *ans = reverseNodesInKGroups(l, k);
    printList(ans);

    return 0;
}
