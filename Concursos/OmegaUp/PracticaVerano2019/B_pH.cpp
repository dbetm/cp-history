#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/pH#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    int n;
    cin >> n;
    if(n >= 0 && n <= 6) cout << "Acido" << endl;
    else if(n == 7) cout << "Neutro" << endl;
    else if(n >= 8 && n <= 14) cout << "Base" << endl;
    else cout << "Are you kidding me?" << endl;
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
