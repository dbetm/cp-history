#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/MCD-facil#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

uint64_t gcd(uint64_t a, uint64_t b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
	_setup();
    uint64_t a, b;
    cin >> a >> b;
    cout << (uint64_t)gcd(a, b) << endl;
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
