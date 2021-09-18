#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1/
// Tag(s): Array
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r + 1;

        sort(arr, arr+n);
        int ans = arr[k-1];

        return ans;
    }
};

int main() {
    fastIO
    int test_case;
    cin >> test_case;

    while(test_case--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int k;
        cin >> k;
        Solution sol;
        cout << sol.kthSmallest(a, 0, n-1, k) << endl;
    }

	return 0;
}
