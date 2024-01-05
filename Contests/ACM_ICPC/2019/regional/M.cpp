#include <bits/stdc++.h>
// https://matcomgrader.com/problem/9646/mountain-ranges/
// Tag(s): Implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = 1;

    for (int i = 0; i < n-1; i++) {
        int cont = 1;
        for (int j = i+1, delta = i; j < n; j++, delta++) {
            if((arr[j] - arr[delta]) <= x) cont++;
            else break;
        }
        ans = max(ans, cont);
    }

    cout << ans << endl;

	return 0;
}
