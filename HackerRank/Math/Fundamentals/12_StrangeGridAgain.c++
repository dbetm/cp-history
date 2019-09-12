#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO();
    lli r, c;
    int cont = 0;
    uint64_t base, ans;
    cin >> r >> c;
    if(r & 1) {
        base = (r-1) * 5;
        for (int64_t i = base; i <= base + 9; i++) {
            if(!(i & 1)) cont++;
            if(cont == c) {
                ans = i;
                break;
            }
        }
    }
    else {
        base = (r-2) * 5;
        for (int64_t i = base; i <= base + 9; i++) {
            if(i & 1) cont++;
            if(cont == c) {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
	return 0;
}
