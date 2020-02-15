#include <bits/stdc++.h>
// Parcialmente Aceptada
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO
	int n, m;
	lli suma = 0;
	cin >> n >> m;

	int matrix[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	// Procesamos la primer columna
	for (int i = 0; i < n; i++) {
		if(matrix[i][0] == 0) {
			for (int j = 0; j < m; j++) {
				matrix[i][j] ^= 1;
			}
		}
	}

	// Procesamos el resto de columnas
	for (int j = 1; j < m; j++) {
		// contar los unos para la col. actual
		int unos = 0;
		for (int i = 0; i < n; i++) {
			unos += matrix[i][j];
		}
		// si hay más unos que ceros, hacemos cambio en esa columna
		if(unos < (n - unos)) {
			for (int i = 0; i < n; i++) {
				matrix[i][j] ^= 1;
			}
		}
	}


	// Hacer la suma
	for (int i = 0; i < n; i++) {
		int sumTemporal = 0;
		for (int j = 0, p = m-1; j < m; j++, p--) {
			sumTemporal += matrix[i][j] * pow(2, p);
		}
		suma += sumTemporal;
	}

	cout << suma << endl;

	return 0;
}
