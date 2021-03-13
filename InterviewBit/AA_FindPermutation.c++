#include <bits/stdc++.h>
// https://www.interviewbit.com/problems/find-permutation/
// Tag(s): Greedy, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

class Solution {
    public:
        vector<int> findPerm(const string A, int B);
};

vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    int start = 1, end = B;

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if(A[i] == 'D') ans.push_back(end--);
        else ans.push_back(start++);
    }

    ans.push_back(end);

    return ans;
}


int main() {
    fastIO
    int n;
    cin >> n;
    string s;
    cin >> s;

    Solution sol;
    vector<int> ans = sol.findPerm(s, n);
    for (int i = 0; i < n-1; i++) cout << ans[i] << " ";
    cout << ans[n-1] << endl;

	return 0;
}
