#include <bits/stdc++.h>
// https://app.codesignal.com/interview-practice/task/cAXEnPyzknC5zgd7x/description
// Tag(s): Backtracing, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

void explore(int n, const int k, int step, vector<int> &sol, vector<vector<int>> &ans) {
    if(n < 0) return;

    n = n - step;
    sol.push_back(step);

    // a solution was found
    if(n == 0) ans.push_back(sol);
    else {
        for (int i = 1; i <= k; ++i) explore(n, k, i, sol, ans);
    }

    sol.pop_back();
}

vector<vector<int>> climbingStaircase(int n, int k) {
    vector<vector<int>> ans;

    for (int i = 1; i <= k; i++) {
        vector<int> sol;
        explore(n, k, i, sol, ans);
    }

    if(ans.empty()) ans.push_back({});

    return ans;
}

int main() {
    fastIO
    int n, k;
    cin >> n >> k;

    auto ans = climbingStaircase(n, k);

    for(auto const &sol : ans) {
        for(auto const x : sol) {
            cout << x << " ";
        }
        cout << endl;
    }

	return 0;
}
