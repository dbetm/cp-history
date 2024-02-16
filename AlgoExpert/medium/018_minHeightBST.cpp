#include <bits/stdc++.h>
//
// tags:
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;


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


void buildBST(vector<int> array, int left, int right, BST* tree) {
    int idx = ((right - left) / 2) + left;

    
}


BST* minHeightBst(vector<int> array) {
    BST* bst = nullptr;

    buildBST(array, 0, array.size(), bst);

    return bst;
}


int main() {
    int root, n;
    cin >> n;
    cin >> root;
    BST bst(root);

    n--;

    while(n--) {
        int value;
        cin >> value;
        bst.insert(value);
    }

    bst.printTree();

	return 0;
}
