#include <bits/stdc++.h>
// // https://omegaup.com/arena/problem/Los-Tacos-del-CECyT-ASINUS#problems
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

int main() {
	_setup();
    int n;
    cin >> n;

    int total = (n - 210) * 40;
    total /= 3;
    int numEstudiantes = total / 80;
    cout << numEstudiantes << endl;
    cout << total << endl;

	return 0;
}
