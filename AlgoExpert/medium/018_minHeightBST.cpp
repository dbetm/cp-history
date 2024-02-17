#include <bits/stdc++.h>
#include "BST.h"
// solved
// tags: binary search, bst, pointers, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;


void buildBST(vector<int> array, int left, int right, BST* tree, bool insert=false) {
    if(left > right) return;

    int idx = ((right - left) / 2) + left;
    //cout << "idx: " << idx << ", left: " << left << ", right: " << right << endl; 
    if(insert) tree->insert(array[idx]);

    if(left < right) {
        // first half
        buildBST(array, left, idx-1, tree, true);
        // second half
        buildBST(array, idx+1, right, tree, true);
    }
}


BST* minHeightBst(vector<int> array) {
    /*My solution
    Time: O(n)
    Space: O(n)
    */
    int left = 0;
    int right = array.size() - 1;
    int idx = ((right - left) / 2) + left; 
    int root = array[idx];

    BST* bst = new BST(root);

    buildBST(array, 0, array.size() - 1, bst, false);

    return bst;
}


int main() {
    int n;
    cin >> n;
    vector<int> array;

    while(n--) {
        int tmp;
        cin >> tmp;
        array.push_back(tmp);
    }

    auto bst = minHeightBst(array);

    bst->printTree();

	return 0;
}
