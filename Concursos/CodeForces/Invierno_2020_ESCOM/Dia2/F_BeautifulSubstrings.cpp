#include <bits/stdc++.h>
//
// tags: implementación, cadenas, hash map
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
#define watch(x) cout << (#x) << " es " << x << endl;

int count(int n, int m, int k);

int main(int argc, char const *argv[]) {
	int t, n, m, k;
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		cout << count(n, m, k) << endl;
	}
	return 0;
}

int count(int n, int m, int k) {
	int ans = 0;
	string a, b;
	//set<pair<int, int>> pares;
	cin >> a >> b;
	int index, index2, k1, k2;
	int mapa[27] = {0};

	for (int i = 0; i <= n-k; i++) {
		k1 = (int)a[i]-97;
		k2 = (int)a[i+k-1]-97;
		mapa[k1]++;
		mapa[k2]++;
		// pair<int, int> ax = {k1, k2};
		// pares.insert(ax);
	}

	// for (auto it = pares.begin(); it != pares.end(); ++it) {
	// 	k1 = it->first; // letra inicio
	// 	k2 = it->second; // letra final
	// 	mapa[k1]++;
	// 	mapa[k2]++;
	// }

	for (int i = 0; i < m; i++) {
		index = (int)b[i]-97;
		if(mapa[index] > 0) {
			for (int j = i; j < m; j++) {
				index2 = (int)b[j]-97;
				if(mapa[index2] > 0) {
					ans++;
					mapa[index]--;
					mapa[index2]--;
				}
			}
		}
	}

	return ans;
}
