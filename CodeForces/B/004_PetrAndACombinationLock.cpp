#include <bits/stdc++.h>
// WA T21
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
int tabla[2701][16];
vi arr;

bool partition(int n);

int main() {
    fastIO
    int n, ai, suma = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        arr.push_back(ai);
        suma += ai;
    }

    if(suma % 360 == 0) cout << "YES" << endl;
    else {
        watch(suma)
        memset(tabla, -1, sizeof tabla);
        cout << (partition(n) ? "YES" : "NO") << endl;
    }

    return 0;
}

bool partition(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if(sum & 1) return false;
    //watch(sum)
    sum /= 2;
    bool tabla[sum + 1][n+1];

    // Casos base
    // 1) Tener 0 elementos en el conjunto y la suma mayor a 0
    for (int i = 0; i <= sum; i++) tabla[i][0] = false;
    // 2) Tener que sumar 0, con n elementos
    for (int j = 0; j <= n; j++) tabla[0][j] = true;

    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            tabla[i][j] = tabla[i][j-1];
            if(arr[j-1] <= i) {
                // Caso 1
                bool incluir = tabla[i-arr[j-1]][j-1];
                // Caso 2
                bool excluir = tabla[i][j-1];
                tabla[i][j] = incluir or excluir;
            }
        }
    }

    // ### Printing matrix ###
    for (int i = 0; i <= sum; i++) {
        for (int j = 0; j <= n; j++) {
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }

    return tabla[sum][n];
}
