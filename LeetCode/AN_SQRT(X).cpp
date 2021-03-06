#include <bits/stdc++.h>
// https://leetcode.com/problems/sqrtx/
// Tag(s): Math, binary search
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
    int mySqrt(int x) {
        int start = 1, end = x;
        int ans = 0, middle;

        while(start <= end) {
            middle = start + ((end - start) / 2);
            //watch(middle)
            if(middle == x/middle) {
                ans = middle;
                break;
            }
            else if(middle < x/middle) {
                ans = middle;
                start = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }

        return ans;
    }
};

int main() {
    fastIO
    int n;
    Solution sol;

    cin >> n;
    cout << sol.mySqrt(n) << endl;

	return 0;
}
