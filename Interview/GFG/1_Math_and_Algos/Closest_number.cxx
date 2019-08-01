#include <bits/stdc++.h>
// checar los casos :D
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int getClosestNumber(int n, int m) {
    int a = abs(n), b = abs(m);
    if(n == 0 || (n == m)) return m;
    int delta = a % b;
    watch(delta)
    if(n < 0) {
        if(abs(n+delta) > abs(n-delta)) return n+delta;
        else return n-delta;
    }
    else {
        return n-delta;
    }
}

int main() {
	fastIO();
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << getClosestNumber(n, m) << endl;
    }
 	return 0;
}
