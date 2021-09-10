#include <bits/stdc++.h>
//
// Tag(s):
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
    Solution();
    int trap(const vector<int> &A);
};

Solution::Solution() {}

int Solution::trap(const vector<int> &A) {
    int ans = 0;
    int n = A.size();
    int a, b;
    int i = (A[0] == 0) ? 1 : 0;

    while(i < n) {
        a = i;
        b = a + 1;
        while(b < n and A[a] < A[b++]) {

        }
        watch(a)
        watch(b)
        if(b == n) break;
        if(A[b] > A[a] and a == 0) {
            i = b;
            continue;
        }

        int base = min(A[a], A[b]);
        int delta = 0;
        for (int k = a+1; k < b; ++k) {
            delta += max(0, base - A[k]);
        }
        ans += delta;

        //i = (delta == 0) ? b : b + 1;
        i = b;
    }

    return ans;
}

int main() {
    fastIO
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    Solution sol;
    cout << sol.trap(A) << endl;

	return 0;
}
