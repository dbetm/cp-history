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

long candies(int n, vector<int> a) {
    int benefits[n];

    benefits[0] = 1;

    for (int i = 1; i < n; ++i) {
        if(a[i-1] < a[i]) {
            benefits[i] = benefits[i-1] + 1;
        }
        else if(a[i-1] == a[i]) {
            benefits[i] = 1;
        }
        else {
            benefits[i] = 1;
            if(benefits[i-1] == 1) { // propagate
                benefits[i-1]++;
            }
        }
    }

    long ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += benefits[i];
    }

    return ans;
}

int main() {
    fastIO
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    long ans = candies(n, arr);
    cout << ans << endl;

	return 0;
}
