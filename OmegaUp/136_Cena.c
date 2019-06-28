#include <stdio.h>
// Parcialmente correcta
int min(int a, int b) {
    return (a < b) ? a : b;
}

int alumnos[30001];

int main() {
    int n, alumno;
    scanf("%d", &n);
    //int alumnos[n+1] = {0};
    int numUnos = 0, numDos = 0;
    int unosEntreDos = 0;
    int dosEntreUnos = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &alumno);
        alumnos[i+1] = alumno;
        if(alumno == 1) {
            numUnos++;
            if(alumnos[i] == 2) unosEntreDos++;
            if(i >= 2 && alumnos[i-1] == 1) unosEntreDos--;
        }
        else {
            numDos++;
            if(alumnos[i] == 1 || alumnos[i] == 0) dosEntreUnos++;
            if(i >= 2 && alumnos[i] != 2 && alumnos[i-1] == 1) dosEntreUnos--;
        }
    }

    if(numUnos == n || numDos == n) printf("%d\n", 0);
    else {
        int sumaTemp = dosEntreUnos + unosEntreDos;
        int menor = min(numDos, numUnos);
        if(sumaTemp > menor) printf("%d\n", menor);
        else printf("%d\n", sumaTemp);
    }

    return 0;
}
