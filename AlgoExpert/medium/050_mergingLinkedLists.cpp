#include <bits/stdc++.h>
#include "LinkedList.h"
// solved
// tags: data-structures, linked-list, implementation
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watch2(x, y) cout << (#x) << " is " << (x) << ", " << (#y) << " is " << (y) << endl;


LinkedList* mergingLinkedLists(
    LinkedList* linkedListOne, LinkedList* linkedListTwo
) {
    /*My solution
    Time: O(n + m)
    Space: O(n)

    Where n is the lenght of the first list and m of the second one.
    */
    LinkedList* ans = nullptr;
    set<LinkedList*> dirs;

    auto tmp = linkedListOne;
    while(tmp != nullptr) {
        dirs.insert(tmp);
        tmp = tmp->next;
    }
    
    auto tmp2 = linkedListTwo;
    while(tmp2 != nullptr) {
        if(dirs.find(tmp2) != dirs.end()) {
            ans = tmp2;
            break;
        }

        tmp2 = tmp2->next;
    }

    return ans;
}


LinkedList* mergingLinkedLists2(
    LinkedList* linkedListOne, LinkedList* linkedListTwo
) {
    /*Proposal (hint)
    Time: O(n + m)
    Space: O(1)
    */
    LinkedList* ans = nullptr;

    int n = linkedListOne->countNodes();
    int m = linkedListTwo->countNodes();

    LinkedList* larger = nullptr;
    LinkedList* shorter = nullptr;
    int largerLen, shortLen;

    if(n > m) {
        larger = linkedListOne;
        shorter = linkedListTwo;
        largerLen = n;
        shortLen = m;
    }
    else {
        larger = linkedListTwo;
        shorter = linkedListOne;
        largerLen = m;
        shortLen = n;
    }

    watch(larger->value)
    watch(shorter->value)

    while(largerLen > shortLen) {
        larger = larger->next;
        largerLen--;
    }

    while(larger != nullptr) {
        if(larger == shorter) return shorter;

        larger = larger->next;
        shorter = shorter->next;
    }

    return nullptr;
}


int main() {
    LinkedList* shared = new LinkedList(1);
    vector<int> values = {4};
    shared->addMany(values);

    LinkedList* listOne = new LinkedList(2);
    vector<int> valuesOne = {3};
    listOne->addMany(valuesOne);
    listOne->addOneExisting(shared);
    listOne->print();

    LinkedList* listTwo = new LinkedList(8);
    vector<int> valuesTwo = {7};
    //listTwo->addMany(valuesTwo);
    listTwo->addOneExisting(shared);
    listTwo->print();

    auto ans = mergingLinkedLists2(listOne, listTwo);

    watch(ans)

    ans->print();

    return 0;
}
