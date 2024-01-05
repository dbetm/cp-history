#include <bits/stdc++.h>
// Aceptado
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
    int n = 5;
    int estaciones[] = {580, 980, 1190, 1250, 1420};

    lli actual;
    cin >> actual;
    if(actual < 540 || actual > 1520) {
        cout << "error" << endl;
        return 0;
    }

    lli distAdelante = MAX;
    lli distAtras = MAX;

    for (int i = 0; i < n; i++) {
        if(actual > estaciones[i]) {
            if(actual - estaciones[i] < distAtras) {
                distAtras = actual - estaciones[i];
            }
        }
        else {
            if(estaciones[i] - actual < distAdelante) {
                distAdelante = estaciones[i] - actual;
            }
        }
    }

    if(distAdelante <= distAtras) {
        cout << "adelante " << distAdelante << endl;
    }
    else {
        cout << "atras " << distAtras << endl;
    }

	return 0;
}
