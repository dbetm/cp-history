#include <bits/stdc++.h>
// Parcialmente correcta
// Tag(s): Es DP
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
    int n;
    double suma1 = 0.0, suma2 = 0.0, aux;
    cin >> n;
    //double arr[n];
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        if(i & 1) suma1 += aux;
        else suma2 += aux;
    }

    printf("%0.1f\n", max(suma1, suma2));

	return 0;
}
