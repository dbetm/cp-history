#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/La-cafeteria-ASINUS#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    double res, x;
    cin >> x;
    res = 1.0 + (150.0)*(x/3.5) - (1.0/3.5);
    cout << (long int)res << endl;
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
