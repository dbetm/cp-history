#include <bits/stdc++.h>
// https://codeforces.com/contest/112/problem/A
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
    string a, b;
    cin >> a >> b;
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    transform(b.begin(), b.end(), b.begin(), ::toupper);

    int ans = a.compare(b);

    if(ans == 0) cout << 0 << endl;
    else if(ans < 0) cout << -1 << endl;
    else cout << 1 << endl;

	return 0;
}
