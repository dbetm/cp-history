#include <bits/stdc++.h>
using namespace std;

// https://app.codesignal.com/interview-practice/task/m9vC4ALaAeudkwRTF/description
// Tag(s): BFS

// Binary trees are already defined with this interface:
template<typename T>
struct Tree {
  Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
  T value;
  Tree *left;
  Tree *right;
};


vector<int> largestValuesInTreeRows(Tree<int> * t) {
    vector<int> ans;
    int nodesNextLevel, maxPerLevel, cont;

    if(t == nullptr) return ans;

    queue<Tree<int> *> q;
    q.push(t);
    nodesNextLevel = 0;
    cont = 1;
    maxPerLevel = -1001;


    while(!q.empty()) {
        auto x = q.front();
        q.pop();

        if(maxPerLevel < x->value) maxPerLevel = x->value;

        --cont;

        if(x->left != nullptr) {
            q.push(x->left);
            nodesNextLevel++;
        }
        if(x->right != nullptr) {
            q.push(x->right);
            nodesNextLevel++;
        }

        if(cont == 0) {
            ans.push_back(maxPerLevel);
            cont = nodesNextLevel;
            nodesNextLevel = 0;
            maxPerLevel = -1001;
        }
    }

    return ans;
}
