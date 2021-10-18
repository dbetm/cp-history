#include <bits/stdc++.h>

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
    ListNode<int> *x = l;
    for (int i = 0; i < k; i++) {
        cout << x->value << "->";
        x = x->next;
    }
    cout << endl;

    return l;
}

ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    if(l == nullptr or k == 1) return l;

    ListNode<int> *aux = nullptr;
    ListNode<int> *left = l, *right = l;
    int cont = 1;

    while(right != nullptr) {

        right = right->next;
        cont++;

        if(cont % k == 0) {
            ListNode<int> *tmpLeft = left;
            ListNode<int> *front = reverseKList(tmpLeft, k-1);

            if(cont == k) l = front;
            else aux->next = front;

            aux = left;
            left = right;
        }
    }
    if(aux != nullptr) aux->next = left;

    /*
    while(right != nullptr) {
        cont++;

        if(cont % k == 0) {
            leftTmp = left;
            //watch(right->value)
            left = right->next;
            right = right->next;
            //watch(right->value)
            //watch(left->value)
            //cont++;
            ListNode<int> *front = reverseKList(leftTmp, k-1);
            watch(front->value)
            if(aux != nullptr) {
                while(front != nullptr and front->next == nullptr) {
                    watch(front->value)
                    front = front->next;
                }
                aux->next = front;
                aux = front;
            }
            else {
                aux = l;
                l = front;
            }
            watch(aux->value)
            cout << "-----------------------" << endl;
        }
        else right = right->next;
        //watch(right->value)
        //if(cont >= 10) break;
    }
    //aux->next = right;
    */

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
