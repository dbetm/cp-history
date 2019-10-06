#include <bits/stdc++.h>
// Respuesta incorrecta
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO();
    lli n, ans = 0, aux = 1;
	cin >> n;
	lli arr[n];

	cin >> arr[0];

	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		if(arr[i-1] * 2 >= arr[i]) {
			aux++;
		}
		else {
			ans = max(ans, aux);
			aux = 1;
		}
	}

	cout << ans << endl;

	return 0;
}
