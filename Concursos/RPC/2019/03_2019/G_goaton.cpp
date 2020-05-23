#include <bits/stdc++.h>
// Equipo Pistas de NULL
// Por Onder
// Aceptado
using namespace std;

int main(){
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double distancia = 100000;
    double menor = 10000;

    for(int i = x1;i <= x2;i++) {
        distancia = sqrt(pow((i-x),2) + pow((y1-y),2));
        if(distancia < menor) menor = distancia;
    }
    for(int i = x1;i <= x2;i++) {
        distancia = sqrt(pow((i-x),2) + pow((y2-y),2));
        if(distancia < menor) menor = distancia;
    }
    for(int i = y1;i <= y2;i++) {
        distancia = sqrt(pow((i-y),2) + pow((x1-x),2));
        if(distancia < menor) menor = distancia;
    }
    for(int i = y1;i <= y2;i++) {
        distancia = sqrt(pow((i-y),2) + pow((x2-x),2));
        if(distancia < menor) menor = distancia;
    }

    printf("%.3f",menor);
    return 0;
}
