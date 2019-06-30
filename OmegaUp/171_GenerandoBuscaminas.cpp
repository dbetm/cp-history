#include <bits/stdc++.h>
//
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    int m, n, minas, x, y;
    cin >> m >> n;
    char juego[n][m] = {{'0'}};
    cin >> minas;
    while(minas--) {
        cin >> y >> x;
        juego[x-1][y-1] = 'M';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(juego[i][j] != 'M') {
                int cont = 0;
                // superior-izquierda
                try {
                    if(juego[i-1][j-1] == 'M') cont++;
                }
                catch(...){}
                // superior
                try {
                    if(juego[i-1][j] == 'M') cont++;
                }
                catch(...){}
                // superior-derecha
                try {
                    if(juego[i-1][j+1] == 'M') cont++;
                }
                catch(...){}
                // izquierda
                try {
                    if(juego[i][j-1] == 'M') cont++;
                }
                catch(...){}
                // derecha
                try {
                    if(juego[i][j+1] == 'M') cont++;
                }
                catch(...){}
                // inferior-izquierda
                try {
                    if(juego[i+1][j-1] == 'M') cont++;
                }
                catch(...){}
                // inferior
                try {
                    if(juego[i+1][j] == 'M') cont++;
                }
                catch(...){}
                // inferior-derecha
                try {
                    if(juego[i+1][j+1] == 'M') cont++;
                }
                catch(...){}
                cout << "##" << cont << endl;
                juego[i][j] = (char)(cont+48);
            }
            //cout << juego[i][j];
        }
        cout << endl;
    }
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
