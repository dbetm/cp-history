#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/maximum-in-struct-array/1/
// Tag(s): Arrays
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

struct Height {
	int feet;
	int inches;
};

int findMax(Height arr[], int n);

// driver program
int main() {
    fastIO
    int t;
    cin >> t;

    while(t--) {
        int n, tmp1, tmp2;
        cin >> n;
        Height arr[n];
        for (int i = 0; i < n; i++) {
            cin >> tmp1 >> tmp2;
            arr[i].feet = tmp1;
            arr[i].inches = tmp2;
        }
        int res = findMax(arr, n);
        cout << res << endl;
    }

    return 0;
}


int findMax(Height arr[], int n) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int tmp = arr[i].inches + arr[i].feet * 12;
        if(tmp > ans) {
            ans = tmp;
        }
    }

    return ans;
}
