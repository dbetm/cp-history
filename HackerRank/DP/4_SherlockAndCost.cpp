#include <bits/stdc++.h>
// Solución incorrecta
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
bool tabla[101];

lli getMaxS(int b[], int n);
void displaySolution(lli sol[], int n);

int main() {
	fastIO
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int b[n];
        //memset(tabla, false, sizeof(tabla));
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            //tabla[b[i]] = true;
        }
        cout << getMaxS(b, n) << endl;
    }
	return 0;
}

lli getMaxS(int b[], int n) {
    lli maxS[n];
    lli hip;
    // Caso base
        // i = 0
    maxS[0] = 0;
    displaySolution(maxS, n);
    // Construimos la solución, "max S to i"
    for (int i = 1; i < n; i++) {
        hip = 0;
        for (int j = b[i]; j >= 1; j--) {
            hip = max(hip, (lli)abs(j - b[i-1]));
        }
        maxS[i] = maxS[i-1] + hip;
    }
    displaySolution(maxS, n);
    return maxS[n-1];
}

void displaySolution(lli sol[], int n) {
    for (int i = 0; i < n-1; i++) {
        cout << sol[i] << " ";
    }
    cout << sol[n-1] << endl;
}
