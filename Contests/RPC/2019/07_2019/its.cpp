#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

int main() {
	fastIO();
    int n;
    cin >> n;
    vi heroes(n);
    vi villanos(n);
    int mayor = -1, otroMayor = -1;
    for (int i = 0; i < n; i++) {
        cin >> heroes[i];
        mayor = max(heroes[i], mayor);
    }
    for (int i = 0; i < n; i++) {
        cin >> villanos[i];
        otroMayor = max(villanos[i], otroMayor);
    }
    if(mayor >= otroMayor) cout << 0 << endl;
    else {
        sort(heroes.rbegin(), heroes.rend());
        sort(villanos.rbegin(), villanos.rend());
        int minimo = INT_MAX;
        for (int i = 0; i < n; i++) {
            if(heroes[i] < villanos[i]) {
                minimo = min(villanos[i] - heroes[i], minimo);
            }
        }
        if(minimo == INT_MAX) cout << 0 << endl;
        else cout << minimo << endl;
    	return 0;
    }
}
