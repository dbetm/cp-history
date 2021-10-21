#include <bits/stdc++.h>
// https://app.codesignal.com/interview-practice/task/2oxNWXTS8eWBzvnRB/description
// Tag(s): DFS, backtracking, trees
using namespace std;

// Binary trees are already defined with this interface:
template<typename T>
struct Tree {
  Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
  T value;
  Tree *left;
  Tree *right;
};

long long int vec2Int(vector<int> &num) {
    int n = num.size();
    long long int sum = 0;

    for(int i = n-1, power = 0; i >= 0; --i, ++power) {
        sum += num[i] * pow(10, power);
    }

    return sum;
}

void dfs(Tree<int> * t, long long int &ans, vector<int> &num) {
    if(t == nullptr) return;

    num.push_back(t->value);

    if(t->left == nullptr and t->right == nullptr) {
        ans += vec2Int(num);
    }
    else {
        dfs(t->left, ans, num);
        dfs(t->right, ans, num);
    }

    num.pop_back();
}

long long digitTreeSum(Tree<int> * t) {
    long long ans = 0;
    vector<int> num;
    dfs(t, ans, num);

    return ans;
}

int main() {
    return 0;
}
