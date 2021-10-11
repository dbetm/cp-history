#include <bits/stdc++.h>
using namespace std;

// https://app.codesignal.com/interview-practice/task/PhNPP45hZGNwpPchi/description
// Tag(s): BFS

//
// Binary trees are already defined with this interface:
template<typename T>
struct Tree {
  Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
  T value;
  Tree *left;
  Tree *right;
};

vector<int> traverseTree(Tree<int> * t) {
    vector<int> ans;

    if(t == nullptr) return ans;

    queue<Tree<int> *> q;
    q.push(t);

    while(!q.empty()) {
        auto x = q.front();
        ans.push_back(x->value);
        q.pop();

        if(x->left != nullptr) q.push(x->left);
        if(x->right != nullptr) q.push(x->right);
    }

    return ans;
}

int main() {
    return 0;
}
