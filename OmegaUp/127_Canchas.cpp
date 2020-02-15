#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " es " << x << endl;

int main() {
    int64_t coor[2][4];
    int64_t area1, area2, areaInter, res;
    cin >> coor[0][0] >> coor[0][1] >> coor[0][2] >> coor[0][3];
    cin >> coor[1][0] >> coor[1][1] >> coor[1][2] >> coor[1][3];
    // Cálculo el área individual de ambas canchas
    area1 = abs(coor[0][0]-coor[0][2]) * abs(coor[0][1]-coor[0][3]);
    area2 = abs(coor[1][0]-coor[1][2]) * abs(coor[1][1]-coor[1][3]);
    // Primer figura: Segunda coordenada
    // Segunda figura: Primer coordenada y segunda coordenada
    int64_t ai1 = (coor[0][2] - coor[1][0]) * (coor[0][3] - coor[1][1]);
    int64_t ai2 = (coor[0][2] - coor[1][2]) * (coor[0][3] - coor[1][3]);
    // Primer figura: Primer coordenada
    // Segunda figura: Primer coordenada y segunda coordenada
    int64_t ai3 = (coor[0][0] - coor[1][0]) * (coor[0][1] - coor[1][1]);
    int64_t ai4 = (coor[0][0] - coor[1][2]) * (coor[0][1] - coor[1][3]);

    areaInter = min(ai1, min(ai2, min(ai3, ai4)));
    // watch(ai1)
    // watch(ai2)
    // watch(ai3)
    // watch(ai4)
    res = area1 + area2 - areaInter;
    cout << (uint64_t)res << endl;
    return 0;
}
