#include <stdio.h>
// https://omegaup.com/arena/problem/El-juego-de-Buddy#problems
int main() {
    int n, f, c;
    scanf("%d", &n);
    int arr[n][n];

    for (int i = 0; i < n*n; i++) {
        scanf("%d %d", &f, &c);
        if(i & 1) arr[f-1][c-1] = 0; // CJ
        else arr[f-1][c-1] = 1; // Buddy
    }

    int diag = arr[0][0];
    int x = 0, y = n-1;
    int diag2 = arr[x][y];
    int contCJ, contBuddy, contDiag = 0, contDiag2 = 0;

    // Barrido por columnas
    for (int i = 0; i < n; i++) {
        contCJ = 0;
        contBuddy = 0;
        if(diag2 == arr[x][y]) contDiag2++;
        for (int j = 0; j < n; j++) {
            if(i == j && diag == arr[i][j]) contDiag++;
            if(arr[i][j] == 0) contCJ++;
            else contBuddy++;
        }
        x++;
        y--;
        if(contCJ == n) {
            printf("El ganador es CJ!\n");
            return 0;
        }
        else if(contBuddy == n) {
            printf("El ganador es Buddy!\n");
            return 0;
        }
    }
    if(contDiag == n) {
        if(diag == 0) {
            printf("El ganador es CJ!\n");
            return 0;
        }
        else {
            printf("El ganador es Buddy!\n");
            return 0;
        }
    }
    if(contDiag2 == n) {
        if(diag2 == 0) {
            printf("El ganador es CJ!\n");
            return 0;
        }
        else {
            printf("El ganador es Buddy!\n");
            return 0;
        }
    }

    // Barrido por filas
    for (int i = 0; i < n; i++) {
        contCJ = 0;
        contBuddy = 0;
        for (int j = 0; j < n; j++) {
            if(arr[j][i] == 0) contCJ++;
            else contBuddy++;
        }
        if(contCJ == n) {
            printf("El ganador es CJ!\n");
            return 0;
        }
        else if(contBuddy == n) {
            printf("El ganador es Buddy!\n");
            return 0;
        }
    }

    printf("Empate!\n");

    return 0;
}
