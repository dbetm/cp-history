#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/La-edad-de-John-Carter#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    int64_t total = 0, dias, n;
    cin >> n;
    while(n--) {
        cin >> dias;
        total += dias;
    }
    cout << (int64_t)(total/365) << endl;

	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
