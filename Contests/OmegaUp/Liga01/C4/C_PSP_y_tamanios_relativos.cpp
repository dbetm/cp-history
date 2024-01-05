#include <bits/stdc++.h>
//
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
    int n;
    cin >> n;
    double a[n];
    double suma = 0, prom, var, dev_std;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        suma += log(a[i]);
    }
    prom = suma / double(n);
    // varianza
    suma = 0;
    for (int i = 0; i < n; i++) {
        suma += (log(a[i]) - prom) * (log(a[i]) - prom);
    }
    var = suma / double(n-1);

    // Calcular desviación estándar
    dev_std = sqrt(var);
    double vs, s, m, l, vl;
    vs = exp(prom-(2*dev_std));
    s = exp(prom-dev_std);
    m = exp(prom);
    l =  exp(prom+dev_std);
    vl = exp(prom+(2*dev_std));

    printf("%0.2f\n", vs);
    printf("%0.2f\n", s);
    printf("%0.2f\n", m);
    printf("%0.2f\n", l);
    printf("%0.2f\n", vl);


	return 0;
}
