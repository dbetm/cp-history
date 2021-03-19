#include <bits/stdc++.h>
// https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = NULL, *leftTail = NULL;
        ListNode *rightHead = NULL, *rightTail = NULL;
        ListNode *ans;

        while(head != NULL) {
            if(head->val < x) {
                if(leftHead == NULL) {
                    leftHead = head;
                    leftTail = head;
                }
                else {
                    ListNode *aux = head;
                    leftTail->next = head;
                    leftTail = aux;
                }
            }
            else {
                if(rightHead == NULL) {
                    rightHead = head;
                    rightTail = head;
                }
                else {
                    ListNode *aux = head;
                    rightTail->next = head;
                    rightTail = aux;
                }
            }

            head = head->next;
        }

        if(leftHead != NULL and rightHead == NULL) {
            leftTail->next = NULL; // to avoid cycles
            ans = leftHead;
        }
        else if(leftHead == NULL and rightHead != NULL) {
            rightTail->next = NULL;
            ans = rightHead;
        }
        else if(leftHead != NULL and rightHead != NULL) {
            rightTail->next = NULL;
            leftTail->next = rightHead;
            ans = leftHead;
        }
        else ans = NULL;

        return ans;
    }
};

int main() {
    fastIO
    int n, x, val;
    Solution sol;

    cin >> n >> x;

    cin >> val;
    ListNode *input = new ListNode(val);
    ListNode *head = input;
    --n;

    while(n--) {
        cin >> val;

        ListNode *aux = new ListNode(val);
        head->next = aux;
        head = aux;
    }

    ListNode *ans = sol.partition(input, x);

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
