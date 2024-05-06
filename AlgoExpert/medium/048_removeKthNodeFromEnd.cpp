#include <bits/stdc++.h>
// solved
// tags: linked-list, data-structure
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watch2(x, y) cout << (#x) << " is " << (x) << ", " << (#y) << " is " << (y) << endl;


class LinkedList {
    public:
        int value;
        LinkedList* next;

        LinkedList(int value) {
            this->value = value;
        }

        void addMany(vector<int> values) {
            auto tmp = this;

            while(tmp->next) {
                tmp = tmp->next;
            }

            for(int value : values) {
                LinkedList* node = new LinkedList(value);
                tmp->next = node;

                tmp = tmp->next;
            }
        }

        vector<int> getNodesInArray() {
            vector<int> nodes;
            auto tmp = this;

            while(tmp != nullptr) {
                nodes.push_back(tmp->value);
                tmp = tmp->next;
            }

            return nodes;
        }

        int countNodes() {
            int cont = 0;
            auto tmp = this;

            while(tmp != nullptr) {
                cont++;
                tmp = tmp->next;
            }

            return cont;
        }

        void print() {
            auto tmp = this;

            while(tmp != nullptr) {
                cout << tmp->value << ", ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

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
