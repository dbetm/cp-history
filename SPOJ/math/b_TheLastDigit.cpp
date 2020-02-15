#include <bits/stdc++.h>
// https://www.spoj.com/problems/LASTDIG/
// Tag(s): Teoría de números
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;

// 0(log(b))
int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;

    while(b > 0) {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

int getLastDigit(int a, int b) {
    return binpow(a, b, 10);
}

int main() {
    fastIO
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << getLastDigit(a, b) << endl;
    }
	return 0;
}
