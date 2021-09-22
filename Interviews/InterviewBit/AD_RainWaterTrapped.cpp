#include <bits/stdc++.h>
// https://www.interviewbit.com/problems/rain-water-trapped/
// Tag(s): implementation, arrays
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
    int i = 0;

    while(n-1 >= 0 and A[n-1] == 0) --n;

    while(n-1 >= 0 and n-2 >= 0 and A[n-1] <= A[n-2]) --n;

    while(i < n and A[i] == 0) ++i;

    while(i < n) {
        a = i;
        b = a + 1;
        pair<int, int> subMax;
        subMax = {A[b], b};

        while(b < n and A[a] > A[b]) {
            if(subMax.first < A[b]) {
                subMax = {A[b], b};
            }
            ++b;
        }

        if(b == n) {
            b = subMax.second;
        }

        int base = min(A[a], A[b]);
        int delta = 0;
        for (int k = a+1; k < b; ++k) {
            delta += max(0, base - A[k]);
        }
        ans += delta;

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
