#include <bits/stdc++.h>
// https://app.codesignal.com/interview-practice/task/RvDFbsNC3Xn7pnQfH
// Tag(s): DS, Linked List, Math
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

template<typename T>
struct ListNode {
    T value;
    ListNode *next;
    ListNode(const T &v) : value(v), next(nullptr) {}
};

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b);
ListNode<int> * reverseLinkedList(ListNode<int> *l);
vector<int> extractDigits(int val, int numPotencias=4);

int main() {
    int n, m, val;
    cin >> n;

    ListNode<int> *a = nullptr, *b = nullptr, *tmp;

    for (int i = 0; i < n; ++i) {
        cin >> val;
        if(a == nullptr) {
            a = new ListNode<int>(val);
            tmp = a;
        }
        else {
            ListNode<int> *aux = new ListNode<int>(val);
            tmp->next = aux;
            tmp = aux;
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> val;
        if(b == nullptr) {
            b = new ListNode<int>(val);
            tmp = b;
        }
        else {
            ListNode<int> *aux = new ListNode<int>(val);
            tmp->next = aux;
            tmp = aux;
        }
    }

    ListNode<int> *ans = addTwoHugeNumbers(a, b);

    int cont = 0;
    while(ans != nullptr and cont++ < 10) {
        cout << ans->value << "-";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    ListNode<int> *headA = a, *headB = b;
    ListNode<int> *ans = nullptr, *tmpAns;
    int carry = 0;

    a = reverseLinkedList(a);
    b = reverseLinkedList(b);

    while(a or b || carry) {
        auto eda = extractDigits((a) ? a->value : 0);
        auto edb = extractDigits((b) ? b->value : 0);

        int subAns = 0;
        for (int i = 0; i < (int)eda.size(); i++) {
            int sum = eda[i] + edb[i] + carry;
            subAns += (sum % 10) * pow(10, i);
            carry = sum / 10;
        }

        if(ans == nullptr) {
            ans = new ListNode<int>(subAns);
            tmpAns = ans;
        }
        else {
            ListNode<int> *aux = new ListNode<int>(subAns);
            tmpAns->next = aux;
            tmpAns = aux;
        }
        if(a) a = a->next;
        if(b) b = b->next;
    }

    a = reverseLinkedList(headA);
    b = reverseLinkedList(headB);

    return reverseLinkedList(ans);
}

ListNode<int> * reverseLinkedList(ListNode<int> *l) {
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

vector<int> extractDigits(int val, int numPotencias) {
    vector<int> ans(numPotencias);
    vector<int> potencias;

    for (int i = 0; i < numPotencias; i++) potencias.push_back(pow(10, i));

    for(int i = numPotencias-1; i >= 0; --i) {
        ans[i] = val / potencias[i];
        val = val % potencias[i];
    }

    return ans;
}
