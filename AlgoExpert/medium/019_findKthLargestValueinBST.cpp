#include <bits/stdc++.h>
#include "BST.h"
// 
// tags:
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;


int findKthLargestValueInBst(BST* tree, int k) {
    int ans = -1;
    bool notFound = true;
    stack<BST*> st;
    st.push(tree);
    cout << "insert: " << tree->value << endl;
    tree = tree->right;

    while(!st.empty() and notFound) {
        cout << "insert: " << tree->value << endl;
        st.push(tree);

        bool isLeaf = st.top()->right == nullptr and st.top()->left == nullptr; 

        if(isLeaf) {
            cout << "backtracking" << endl;

            while(!st.empty()) {
                auto node = st.top();
                st.pop();

                k -= 1;
                cout << "checking: " << node->value << endl;
                if(k == 0) {
                    ans = node->value;
                    notFound = false;
                    break;
                }

                if(node->left) {
                    tree = node->left;
                    break;
                }
            }
        }
        else {
            if(tree->right) tree = tree->right;
            else if(tree->left) tree = tree->left;
        }
    }

    return ans;
}


int main() {
    int root, n, k;
    cin >> n;
    cin >> root;
    BST bst(root);

    n--;

    while(n--) {
        int value;
        cin >> value;
        bst.insert(value);
    }
    cin >> k;

    bst.printTree();

    int ans = findKthLargestValueInBst(&bst, k);
    cout << ans << endl;

	return 0;
}
