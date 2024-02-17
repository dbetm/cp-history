#ifndef BST_H // Include guard
#define BST_H


#include <bits/stdc++.h>
using namespace std;


class BST {
    public:
        int value;
        BST* left;
        BST* right;

        BST(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }

        void insert(int value) {
            if (value < this->value) {
                if (left == nullptr) {
                    left = new BST(value);
                }
                else {
                    left->insert(value);
                }
            }
            else {
                if (right == nullptr) {
                    right = new BST(value);
                }
                else {
                    right->insert(value);
                }
            }
        }

        void printTree() {
            queue<BST*> myQ;
            myQ.push(this);
            myQ.push(NULL);
            // we insert NULL to point the end of a level

            while(!myQ.empty()) {
                BST *node = myQ.front();
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