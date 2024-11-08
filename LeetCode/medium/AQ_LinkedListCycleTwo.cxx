#include <bits/stdc++.h>
// https://leetcode.com/problems/linked-list-cycle-ii/
// Tag(s): Estructuras de datos, matemáticas
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool hasCycle = false;

        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle) return NULL;
        slow = head;

        while(slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main() {
    fastIO
    int n, val, pos;
    Solution sol;

    cin >> n >> pos;

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

    ListNode *aux = input;

    while(pos > 0) {
        aux = aux->next;
        --pos;
    }

    if(pos != -1) head->next = aux;

    ListNode *ans = sol.detectCycle(input);

    printLinkedList(ans);

	return 0;
}

void printLinkedList(ListNode* list) {
    unordered_map<ListNode*, int> nodos;

    while(list != NULL) {
        if(nodos.count(list)) {
            break;
        }
        cout << list->val << " ";
        nodos.insert({list, list->val});
        list = list->next;
    }
    cout << endl;
}
