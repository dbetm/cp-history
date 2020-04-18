#include <bits/stdc++.h>
// Parcialmente correcta (36%)
// Tag(s): Implementación
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
int matrix[101][101];
int l;
bool puedoGanar(int i, int j);

int main() {
    fastIO
    int n, x, y, s;
    cin >> l;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> s;
        if(s == 1) matrix[l-y+1][x] = 2;
        else matrix[l-y+1][x] = 1;
    }

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            if(matrix[i][j] == 0) {
                if(puedoGanar(i, j)) {
                    cout << j << " " << (l-i+1) << endl;
                }
            }
        }
    }

	return 0;
}

bool puedoGanar(int i, int j) {
    // barrido horizontal
    int contDer = 1, contIzq = 1;
    bool f1 = true, f2 = true;
    for (int x = 0; x < 4; x++) {
        if(j+1 + x < l && f1) {
            if(matrix[i][j+1+x] == 1) {
                contDer++;
            }
            else f1 = false;
        }
        if(j-1-x > 0 && f2) {
            if(matrix[i][j-1-x] == 1) {
                contIzq++;
            }
            else f2 = false;
        }
    }
    if(contDer + contIzq >= 5) return true;

    // barrido vertical
    int contArriba = 1, contAbajo = 1;
    f1 = true;
    f2 = true;
    for (int x = 0; x < 4; x++) {
        if(i+1 + x < l && f1) {
            if(matrix[i+1+x][j] == 1)
                contAbajo++;
            else f1 = false;
        }
        if(i-1-x > 0 && f2) {
            if(matrix[i-1-x][j] == 1)
                contArriba++;
            else f2 = false;
        }
    }
    if(contAbajo + contArriba >= 5) return true;

    // barrido diagonal
    int cont1 = 1, cont2 = 1, cont3 = 1, cont4 = 1;
    f1 = true, f2 = true;
    bool f3 = true, f4 = true;

    for (int x = 0; x < 4; x++) {
        if(i-x-1 > 0 && j-x-1 > 0 && f1) {
            if(matrix[i-x-1][j-x-1] == 1)
                cont1++;
            else f1 = false;
        }
        if(i-x-1 > 0 && j+x+1 < l && f2) {
            if(matrix[i-x-1][j+x+1] == 1)
                cont2++;
            else f2 = false;
        }
        if(i+x+1 > 0 && j-x-1 > 0 && f3) {
            if(matrix[i+x+1][j-x-1] == 1)
                cont3++;
            else f3 = false;
        }
        if(i+x+1 > 0 && j+x+1 < l && f4) {
            if(matrix[i+x+1][j+x+1] == 1)
                cont4++;
            else f4 = false;
        }
    }
    if(cont1 + cont2 >= 5) return true;
    else if(cont3 + cont4 >= 5) return true;

    return false;
}
