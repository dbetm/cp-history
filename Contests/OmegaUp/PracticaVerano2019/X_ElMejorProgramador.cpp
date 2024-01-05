#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Comparacion-programadores#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    pair<string, int> p1;
    pair<string, int> p2;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    if(p1.second > p2.second) cout << p1.first << endl;
    else cout << p2.first << endl;
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
