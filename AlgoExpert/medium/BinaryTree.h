#ifndef BinaryTree_H // Include guard
#define BinaryTree_H


#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
        void insert(vector<int> values) {
            queue<BinaryTree*> items;
            // root was already inserted
            items.push(this);
            items.push(nullptr);
            int idx = 1, n = values.size();

            while(!items.empty() and idx < n) {
                auto node = items.front();
                items.pop();

                if(node == nullptr and !items.empty()) {
                    // put the mark of the end of the next level
                    items.push(nullptr);
                }
                else {
                    if(idx < n) {
                        node->left = new BinaryTree(values[idx]);
                        idx += 1;
                        items.push(node->left);
                    }
                    if(idx < n) {
                        node->right = new BinaryTree(values[idx]);
                        idx += 1;
                        items.push(node->right);
                    }
                }
            }
        }

        void print() {
            queue<BinaryTree*> myQ;
            myQ.push(this);
            myQ.push(NULL);
            // we insert NULL to point the end of a level

            while(!myQ.empty()) {
                BinaryTree *node = myQ.front();
                myQ.pop();

                if(node == NULL) {
                    if(!myQ.empty()) {
                        myQ.push(NULL);
                    }
                    cout << endl;
                }
                else {
                    cout << node->value << " ";
                    if(node->left) myQ.push(node->left);
                    if(node->right) myQ.push(node->right);
                }
            }

            cout << "------------------------------" << endl;
        }
};


#endif