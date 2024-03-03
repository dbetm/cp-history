#ifndef BinaryTreeLinked_H // Include guard
#define BinaryTreeLinked_H


#include <bits/stdc++.h>
using namespace std;


class BinaryTreeLinked {
    public:
        int value;
        BinaryTreeLinked* left = nullptr;
        BinaryTreeLinked* right = nullptr;
        BinaryTreeLinked* parent = nullptr;

        BinaryTreeLinked(int value){
            this->value = value;
        }

        BinaryTreeLinked* insertSingle(int value, bool toLeft=true) {
            if(toLeft) {
                this->left = new BinaryTreeLinked(value);
                this->left->parent = this;
                return this->left;
            }

            this->right = new BinaryTreeLinked(value);
            this->right->parent = this;
            return this->right;
        }

        void print() {
            queue<BinaryTreeLinked*> myQ;
            myQ.push(this);
            myQ.push(NULL);
            // we insert NULL to point the end of a level

            while(!myQ.empty()) {
                BinaryTreeLinked *node = myQ.front();
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