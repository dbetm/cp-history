#include <bits/stdc++.h>
#include "LinkedList.h"
// solved
// tags: linked-list, data-structure
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watch2(x, y) cout << (#x) << " is " << (x) << ", " << (#y) << " is " << (y) << endl;



void removeKthNodeFromEnd(LinkedList* head, int k) {
    /*My proposal
    Time: O(n)
    Space: O(1)
    */
    int n = head->countNodes();
    int delta = n - k;

    if(delta == 0) {
        LinkedList* nextHead = head->next;
        head->value = nextHead->value;
        head->next = nextHead->next;
    }
    else {
        auto tmp = head;
        int cont = 0;

        while(cont < delta - 1) {
            tmp = tmp->next;
            cont++;
        }

        tmp->next = tmp->next->next;
    }
}


int main() {
    LinkedList* list = new LinkedList(0);

    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    list->addMany(values);

    list->print();

    removeKthNodeFromEnd(list, 1);

    list->print();

    return 0;
}
