#include <iostream>
// https://omegaup.com/arena/problem/Cuadro-Magico#problems
using namespace std;

int main() {
    int sumaFila, sumaCol, sumaDiag1 = 0, sumaDiag2 = 0;
    int matriz[3][3];
    bool bandera = true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> matriz[i][j];

    // Filas
    for (int i = 0; i < 3; i++){
        sumaFila = 0;
        for (int j = 0; j < 3; j++)
            sumaFila += matriz[j][i];
        if(sumaFila != 15) {
            bandera = false;
            break;
        }
    }

    if(bandera) {
        // Columnas
        int r = 2;
        for (int i = 0; i < 3; i++){
            sumaCol = 0;
            sumaDiag2 += matriz[i][r];
            for (int j = 0; j < 3; j++) {
                sumaCol += matriz[i][j];
                if(i == j) {
                    sumaDiag1 += matriz[i][j];
                }
            }
            if(sumaCol != 15) {
                bandera = false;
                break;
            }
            r--;
        }
        if(sumaDiag1 != 15 || sumaDiag2 != 15) {
            bandera = false;
        }
    }

    if(bandera) cout << "SI" << endl;
    else cout << "NO" << endl;

    return 0;
}
