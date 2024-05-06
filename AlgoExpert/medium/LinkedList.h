#ifndef LinkedList_H // Include guard
#define LinkedList_H


#include <bits/stdc++.h>
using namespace std;


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


#endif