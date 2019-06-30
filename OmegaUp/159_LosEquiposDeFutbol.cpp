#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Los-Equipos-de-Futbol-ASINUS#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int64_t calc(int n, int r);

int main() {
	_setup();
    int64_t n;
    cin >> n;
    n--;
    int64_t res = calc(n, 4);
    cout << res << endl;
    cout << (res > 2000) << endl;

	return 0;
}

int64_t calc(int n, int r) {
    int64_t p = 1;
    for (int i = 0; i < r; i++) {
        p *= (n-i);
    }
    return p;
}
