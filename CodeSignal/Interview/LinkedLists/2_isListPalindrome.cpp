#include <bits/stdc++.h>
// https://app.codesignal.com/interview-practice/task/HmNvEkfFShPhREMn4/description
// Tag(s): DS, Linked Lists
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

ListNode<int> * reverseList(ListNode<int> *l) {
    ListNode<int> *faster = l->next;
    l->next = nullptr;

    while(faster != nullptr) {
        ListNode<int> *tmp = faster->next;
        faster->next = l;
        l = faster;
        faster = tmp;
    }

    return l;
}

/* A better solution */
bool isListPalindrome(ListNode<int> *l) {
    int n = countElements(l);

    if(n == 0 or n == 1) return true;

    bool ans = true;
    ListNode<int> *left = l;
    ListNode<int> *right = l;

    // first half
    for (int i = 0; i < (n/2); ++i) {
        right = right->next;
    }

    if(n & 1) right = right->next;

    right = reverseList(right);
    ListNode<int> *aux = right;

    // second half
    for (int i = 0; i < (n/2); ++i) {
        if(left->value != right->value) {
            ans = false;
            break;
        }
        left = left->next;
        right = right->next;
    }

    aux = reverseList(aux);

    return ans;
}

/* Hardcode solution */
bool isListPalindrome2(ListNode<int> *l) {
    int n = countElements(l);
    int aux = 0, p = 5, power = 1, m = 10993;
    int half = n/2;
    int leftSum = 0, rightSum = 0;
    int flip = -1;
    int i;
    for (i = 0; i < half; ++i, ++power) {
        if(n & 1 and i == half) break;
        aux = aux ^ l->value;
        leftSum += (flip) * l->value * ((p % m) * (power % m) % m);
        l = l->next;
        flip *= -1;
    }

    if(n & 1) {
        l = l->next;
        ++i;
    }
    flip *= -1;
    --power;

    for (int j = i; j < n; ++j, --power) {
        aux = aux ^ l->value;
        rightSum += (flip) * l->value * ((p % m) * (power % m) % m);
        l = l->next;
        flip *= -1;
    }

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
