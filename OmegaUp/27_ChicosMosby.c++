#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/OMI-2016-Chicos-Mosby/#problems
// Tags: maths, implementation
using namespace std;
typedef long long int lli;


int main() {
	lli n, m;
	cin >> n >> m;

	int cont = 0, multi;

	if(m == n) {
		cont = 1;
	}
	else {
		do {
			if(m > n) {
				multi = m / n;
				m = m - (n * multi);
			}
			else {
				multi = n / m;
				n = n - (m * multi);
			}
			cont += multi;
		} while(m >= 1 and n >= 1);
	}

	cout << cont << endl;

	return 0;
}
