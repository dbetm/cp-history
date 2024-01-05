#include <bits/stdc++.h>
// https://codeforces.com/group/4Drl6UlALp/contest/264638/problem/C
// tags: implementación, cadenas
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
#define watch(x) cout << (#x) << " es " << x << endl;

string calc(int n) {
	string ans = "", cadena;
	vector <set<string>> conjuntos;
	int numConjuntos = 0;
	bool flag;
	vector <int> tamanios;

	for (int i = 0; i < n; i++){
		cin >> cadena;
		flag = false;

		for (int i = 0; i < numConjuntos; i++) {
			int antes = conjuntos[i].size(), despues;
			conjuntos[i].insert(cadena);
			despues = conjuntos[i].size();
			if(despues > antes) {
				flag = true;
				break;
			}
		}

		if(!flag) {
			set<string> aux;
			aux.insert(cadena);
			conjuntos.push_back(aux);
			numConjuntos++;
		}
	}

	for (int i = 0; i < numConjuntos; i++) {
		tamanios.push_back(conjuntos[i].size());
	}

	sort(tamanios.begin(), tamanios.end());
	int tam = tamanios.size();
	for (int i = 0; i < tam; i++){
		ans += to_string(tamanios[i]);
	}
	return ans;
}

int main() {
	fastIO
	int n, cont = 1;

	while(true) {
		cin >> n;
		if(n == 0) break;
		cout << "Case " << cont << ": " << calc(n) << endl;
		cont++;
	}

	return 0;
}
