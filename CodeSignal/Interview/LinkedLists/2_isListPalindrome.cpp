#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

int countElements(ListNode<int> *l) {
    ListNode<int> *tmp = l;
    int ans = 0;
    while(tmp != nullptr) {
        ++ans;
        tmp = tmp->next;
    }

    return ans;
}

bool isListPalindrome(ListNode<int> *l) {
    int n = countElements(l);
    int aux = 0;
    int half = n/2;
    int leftSum = 0, rightSum = 0;
    int flip = -1;
    int i;
    for (i = 0; i <= half; ++i) {
        if(n & 1 and i == half) break;
        aux = aux ^ l->value;
        leftSum += (flip) * l->value;
        l = l->next;
        flip *= -1;
    }

    if(n & 1) l = l->next;

    for (int j = i+1; j < n; ++j) {
        aux = aux ^ l->value;
        rightSum += (flip) * l->value;
        l = l->next;
        flip *= -1;
    }
    watch(aux)
    watch(leftSum)
    watch(rightSum)

    return aux == 0 and leftSum == rightSum;
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
    int n, val;
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

    cout << isListPalindrome(l) << endl;

    return 0;

}
