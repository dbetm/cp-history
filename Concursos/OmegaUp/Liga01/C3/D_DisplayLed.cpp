#include <bits/stdc++.h>
// AC
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
int pantalla[301][301];
int r, c;
int areaMenor = 90001;
int areaMayor = 0;
int procesar(int i, int j);

int main() {
    fastIO
    memset(pantalla, -1, sizeof pantalla);
    cin >> r >> c;
    char aux;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> aux;
            if(aux == 'X')
                pantalla[i][j] = 2;
            else
                pantalla[i][j] = 0;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(pantalla[i][j] == 2) {
                int familia = procesar(i, j);
                areaMayor = max(areaMayor, familia);
                areaMenor = min(areaMenor, familia);
            }
        }
    }

    cout << areaMayor << endl;
    if(areaMenor == 90001) cout << 0 << endl;
    else cout << areaMenor << endl;

	return 0;
}

int procesar(int i, int j) {
    int cont = 1;
    if(pantalla[i][j] == 0) return 0;

    pantalla[i][j] = 0;
    // Arriba
    if(i - 1 >= 0 && pantalla[i-1][j] == 2)
        cont += procesar(i-1, j);
    // Abajo
    else if(i + 1 < r && pantalla[i+1][j] == 2)
        cont += procesar(i+1, j);
    // Izquierda
    else if(j - 1 >= 0 && pantalla[i][j-1] == 2)
        cont += procesar(i, j-1);
    // Derecha
    else if(j + 1 < c && pantalla[i][j+1] == 2)
        cont += procesar(i, j+1);

    return cont;
}
