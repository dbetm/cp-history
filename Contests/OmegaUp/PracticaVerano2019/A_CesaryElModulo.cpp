#include <bits/stdc++.h>
//
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
// https://omegaup.com/arena/problem/David-y-el-modulo-ETITC#problems
void _setup();

int main() {
	_setup();
    int64_t a, b, s, suma;
    cin >> a >> b >> s;
    suma = a + b;
    if((suma % s) == 0) cout << "SI" << endl;
    else cout << "NO" << endl;

	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
