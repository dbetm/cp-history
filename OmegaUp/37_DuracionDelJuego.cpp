#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Duracion-del-juego#problems
using namespace std;

int main(int argc, char const *argv[]) {
    int hInicio, hFin;
    cin >> hInicio >> hFin;
    if(hFin == hInicio) cout << 24 << endl;
    else if(hFin > hInicio) cout << hFin-hInicio << endl;
    else {
        int res = (24-hInicio) + hFin;
        if(res == 0 && hInicio == 24) cout << 24 << endl;
        else cout << (24-hInicio) + hFin << endl;
    }
    return 0;
}
