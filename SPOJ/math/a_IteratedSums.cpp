#include <bits/stdc++.h>
// https://www.spoj.com/problems/SMPSUM/
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
    int64_t sum, a, b;
    cin >> a >> b;
    sum = (b * (b+1) * (2*b+1)) / 6;
    a--;
    sum -= (a * (a+1) * (2*a+1)) / 6;
    cout << sum << endl;

	return 0;
}
