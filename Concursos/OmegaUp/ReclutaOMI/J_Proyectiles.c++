#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Proyectiles#problems
using namespace std;
typedef pair<int, int> pii;
typedef vector< pii > vi;

bool buscar(vi &, int, int);
int busquedaBinaria(vi &, int, int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int x, y;
    cin >> n >> k;
    vi coordenadas;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coordenadas.push_back(make_pair(x, y));
    }

    sort(coordenadas.begin(), coordenadas.end());

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        if(buscar(coordenadas, x, y)) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}

bool buscar(vi &coordenadas, int x, int y) {
    bool ans = false;
    int tam = coordenadas.size();
    int index = busquedaBinaria(coordenadas, 0, tam-1, x);
    if(index == -1) return false;
    else {
        if(coordenadas[index].second == y) {
            return true;
        }
        int indexOriginal = index;
        index++;
        // hacia arriba
        while(index < tam && coordenadas[index].first == x) {
            if(coordenadas[index].second == y) {
                ans = true;
                break;
            }
            index++;
        }
        if(!ans) {
            index = indexOriginal;
            index--;
            // hacia abajo
            while(index >= 0 && coordenadas[index].first == x) {
                if(coordenadas[index].second == y) {
                    ans = true;
                    break;
                }
                index--;
            }
        }
    }

    return ans;
}

int busquedaBinaria(vi &coordenadas, int l, int r, int target) {
    int guess = floor((l + r) / 2);
    if(l > r) return -1;
    else if(coordenadas[guess].first == target) return guess;
    else if(coordenadas[guess].first < target) l = guess + 1;
    else r = guess - 1;
    return busquedaBinaria(coordenadas, l, r, target);
}
