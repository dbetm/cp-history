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
    int n;
    int cont = 0;
    int primero, siguiente;
    cin >> n;
    cin >> primero;
    n--;
    while(n--) {
        cin >> siguiente;
        if(siguiente - primero >= 20) cont++;
    }
    if(365)

    cout << cont << endl;
	return 0;
}
