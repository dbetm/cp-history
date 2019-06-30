#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Practica-Ciclos-ASINUS#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;

void _setup() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
	_setup();
    int n, num;
    lli total = 0x00;
    cin >> n;
    while(n--) {
        cin >> num;
        total += num;
    }
    cout << total << endl;
	return 0;
}
