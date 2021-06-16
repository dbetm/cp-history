#include <bits/stdc++.h>
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Tag(s): Árboles
// NO COMPLETE IMPLEMENTED HERE
using namespace std;
/**
 * Definition for a binary tree node.
**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Point {
    TreeNode* node;
    int col;
    int row;

    Point(TreeNode* node) : node(node), row(0), col(0) {}
    Point(TreeNode* node, int row, int col) : node(node), row(row), col(col) {}
};

struct pValue {
    int col;
    int row;
    int val;
    pValue(int row, int col, int val) : row(row), col(col), val(val) {}
};

struct lessThanKey {
    inline bool operator() (const pValue& s1, const pValue& s2) {
        return s1.val < s2.val;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<Point> q;
        vector< vector<int> > ans;

        if(root == NULL) return ans;

        map<int, vector<pValue> > columns;

        q.push({root, 0, 0});

        while(!q.empty()) {
            Point currentNode = q.front();
            q.pop();

            columns[currentNode.col].push_back({currentNode.row, currentNode.col, currentNode.node->val});


            if(currentNode.node->left != NULL) {
                q.push({currentNode.node->left, currentNode.row + 1, currentNode.col - 1});
            }
            if(currentNode.node->right != NULL) {
                q.push({currentNode.node->right, currentNode.row + 1, currentNode.col + 1});
            }
        }

        for(auto it = columns.begin(); it != columns.end(); it++) {
            vector<pValue> aux = it->second;

            int x1 = 0, x2 = 0;
            int auxLen = aux.size();

            while(x1 < auxLen) {
                while(x2 < auxLen and aux[x1].row == aux[x2].row) {
                    x2++;
                }

                if(x1 == x2) {
                    x1++;
                    x2++;
                }
                else {
                    int upperBound = min(auxLen, x2);
                    sort(aux.begin() + x1, aux.begin() + upperBound, lessThanKey());

                    x1 = x2;
                }
            }


            vector<int> aux2;

            for(int i = 0; i < aux.size(); i++) {
                aux2.push_back(aux[i].val);
            }

            ans.push_back(aux2);
        }

        return ans;
    }
};

int main() {
	return 0;
}
