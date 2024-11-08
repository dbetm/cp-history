#include <bits/stdc++.h>
// https://leetcode.com/problems/add-two-numbers/
// Tag(s): Estructuras de datos
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode* list);

class Solution {
public:
    ListNode* reverseList(ListNode* list) {
        ListNode *current = list;
        ListNode *previous = NULL;

        while(current != NULL) {
            ListNode *aux = current->next;
            current->next = previous;

            previous = current;
            current = aux;
        }

        return previous;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;

        ListNode *head = NULL;

        while(l1 != NULL and l2 != NULL) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;

            ListNode *aux = new ListNode(sum);
            aux->next = head;
            head = aux;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum %= 10;

            ListNode *aux = new ListNode(sum);
            aux->next = head;
            head = aux;

            l1 = l1->next;
        }

        while(l2 != NULL) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum %= 10;

            ListNode *aux = new ListNode(sum);
            aux->next = head;
            head = aux;

            l2 = l2->next;
        }

        if(carry > 0) {
            ListNode *aux = new ListNode(carry);
            aux->next = head;
            head = aux;
        }

        //printLinkedList(head);

        return reverseList(head);
    }
};

int main() {
    fastIO
    int m, n, val;
    Solution sol;

    cin >> m >> n;

    cin >> val;
    ListNode *l1 = new ListNode(val);
    ListNode *head = l1;
    --m;

    while(m--) {
        cin >> val;

        ListNode *aux = new ListNode(val);
        head->next = aux;
        head = aux;
    }
    head = NULL;

    cin >> val;
    ListNode *l2 = new ListNode(val);
    head = l2;
    --n;

    while(n--) {
        cin >> val;

        ListNode *aux = new ListNode(val);
        head->next = aux;
        head = aux;
    }
    head = NULL;

    ListNode *ans = sol.addTwoNumbers(l1, l2);

    printLinkedList(ans);

	return 0;
}

void printLinkedList(ListNode* list) {
    while(list != NULL) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}
