#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t coor[2][4];
    int64_t area1, area2, areaInter, res;
    cin >> coor[0][0] >> coor[0][1] >> coor[0][2] >> coor[0][3];
    cin >> coor[1][0] >> coor[1][1] >> coor[1][2] >> coor[1][3];

    area1 = abs(coor[0][0]-coor[0][2]) * abs(coor[0][1]-coor[0][3]);
    area2 = abs(coor[1][0]-coor[1][2]) * abs(coor[1][1]-coor[1][3]);
    int64_t base = 0;
    int64_t altura = 0;
    // Barrido horizontal
    int64_t mayor = max(coor[0][0], coor[0][2]);
    int64_t menor = min(coor[0][0], coor[0][2]);

    if(menor <= coor[1][0]) {
        for (int i = menor; i <= mayor; i++) {
            if(i > coor[1][0] && i <= coor[1][2]) base++;
            else if(i < coor[1][0] && i >= coor[1][2]) base++;
        }
    }
    else {
        for (int i = menor; i <= mayor; i++) {
            if(i >= coor[1][0] && i < coor[1][2]) base++;
            else if(i <= coor[1][0] && i > coor[1][2]) base++;
        }
    }

    // Barrido vertical
    mayor = max(coor[0][1], coor[0][3]);
    menor = min(coor[0][1], coor[0][3]);

    if(menor <= coor[1][1]) {
        for (int i = menor; i <= mayor; i++) {
            if(i > coor[1][1] && i <= coor[1][3]) altura++;
            else if(i < coor[1][1] && i >= coor[1][3]) altura++;
        }
    }
    else {
        for (int i = menor; i <= mayor; i++) {
            if(i >= coor[1][1] && i < coor[1][3]) altura++;
            else if(i <= coor[1][1] && i > coor[1][3]) altura++;
        }
    }

    areaInter = base * altura;
    res = area1 + area2 - areaInter;
    cout << (uint64_t)res << endl;
    return 0;
}
