#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " es " << x << endl;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*
	2,1,4,3,5

	(2*2+1*1+4*4)*(3+5) = 168

	*/
	int n;
	cin >> n;

	vector <int> v(n);
	uint64_t sumaCuadrados = 0;
	uint64_t suma = 0;

	cin >> v[0];
	sumaCuadrados += v[0]*v[0];

	for (int i = 1; i < n; i++) {
		cin >> v[i];
		suma += v[i];
	}


    uint64_t ans = suma * sumaCuadrados;

	for (int i = 1; i < n; i++) {
		suma -= v[i];
		sumaCuadrados += v[i] * v[i];
		ans = max(ans, suma * sumaCuadrados);
	}

	cout << (uint64_t)ans << endl;

	return 0;
}
