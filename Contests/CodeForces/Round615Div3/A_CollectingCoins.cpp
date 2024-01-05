#include <bits/stdc++.h>
// TLE
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

int main() {
	fastIO
    lli t, a, b, c, n;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> n;
        lli maxi = max(a, max(b, c));
        lli d = (a + b + c) - (3*maxi);
        d += n;
        bool flag;
        if(d >= 0) {

        }
        else flag = false;
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}
