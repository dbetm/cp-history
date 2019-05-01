#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/plantas-vs-plantas#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, mayor = -1, aux, minutos;
    cin >> n;
    vector <int> plantas(n);
    stack <int> pila, cuantos;
    for(int i = 0; i < n; i++) cin >> plantas[i];
    for (int i = n-1; i >= 0; i--) {
        aux = 0;
        while(!pila.empty() && plantas[i] > pila.top()) {
            minutos = cuantos.top();
            if(aux < minutos) aux = minutos;
            else aux++;
            pila.pop();
            cuantos.pop();
        }

        pila.push(plantas[i]);
        cuantos.push(aux);
        if(mayor < aux) mayor = aux;
    }

    cout << mayor << endl;
    return 0;
}
