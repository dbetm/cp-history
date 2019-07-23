#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Adivina-El-Operador#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    int a, b, res;
    cin >> a >> b >> res;
    if((a + b) == res) cout << "+" << endl;
    else if((a - b) == res) cout << "-" << endl;
    else if((a * b) == res) cout << "*" << endl;
    else if(b != 0 && ((a / b) == res)) cout << "/" << endl;
    else cout << "D:" << endl;
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
