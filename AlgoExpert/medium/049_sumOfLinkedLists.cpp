#include <bits/stdc++.h>
#include "LinkedList.h"
// solved
// tags: linked-list, data-structure
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watch2(x, y) cout << (#x) << " is " << (x) << ", " << (#y) << " is " << (y) << endl;


LinkedList* sumOfLinkedLists(
    LinkedList* linkedListOne, LinkedList* linkedListTwo
) {
    /* My proposal
    Time: O(max(n,m))
    Space: O(max(n, m))
    */
    int carry = 0, sum = 0, res = 0;

    auto l1 = linkedListOne;
    auto l2 = linkedListTwo;
    LinkedList* ans = nullptr;
    LinkedList* tmp = nullptr;

    while(l1 != nullptr and l2 != nullptr) {
        sum = l1->value + l2->value + carry;
        res = sum % 10;

        carry = (sum >= 10) ? 1 : 0;

        if(ans == nullptr) {
            ans = new LinkedList(res);
            tmp = ans;
        }
        else {
            tmp->next = new LinkedList(res);
            tmp = tmp->next;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 != nullptr) {
        sum = l1->value + carry;
        res = sum % 10;
        carry = (sum >= 10) ? 1 : 0;

        tmp->next = new LinkedList(res);
        tmp = tmp->next;

        l1 = l1->next;
    }

    while(l2 != nullptr) {
        sum = l2->value + carry;
        res = sum % 10;
        carry = (sum >= 10) ? 1 : 0;

        tmp->next = new LinkedList(res);
        tmp = tmp->next;

        l2 = l2->next;
    }

    if(carry >= 1) {
        tmp->next = new LinkedList(carry);
    }

    return ans;
}


int main() {
    LinkedList* listOne = new LinkedList(2);
    vector<int> valuesOne = {4, 7, 1};
    listOne->addMany(valuesOne);
    listOne->print();

    LinkedList* listTwo = new LinkedList(9);
    vector<int> valuesTwo = {4, 5};
    listTwo->addMany(valuesTwo);
    listTwo->print();

    auto ans = sumOfLinkedLists(listOne, listTwo);

    ans->print();

    return 0;
}
