#include <bits/stdc++.h>

using namespace std;

int formingMagicSquare(int S[][3]);

int main(int argc, char const *argv[]) {
    int S[3][3];
    for(unsigned int i = 0; i < 3; i++) {
        for(unsigned int j = 0; j < 3; j++) {
            cin >> S[i][j];
        }
    }
    //Print the cost
    cout << formingMagicSquare(S) << endl;
    return 0;
}

int formingMagicSquare(int S[][3]) {
    int Model[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    int cost = 72, aux;
    for(unsigned int k = 0; k < 8; k++) {
        if(k == 1) {
            Model[0][0] = 8;
            Model[0][1] = 1;
            Model[0][2] = 6;

            Model[1][0] = 3;
            Model[1][1] = 5;
            Model[1][2] = 7;

            Model[2][0] = 4;
            Model[2][1] = 9;
            Model[2][2] = 2;
        }
        else if(k == 2) {
            Model[0][0] = 8;
            Model[0][1] = 3;
            Model[0][2] = 4;

            Model[1][0] = 1;
            Model[1][1] = 5;
            Model[1][2] = 9;

            Model[2][0] = 6;
            Model[2][1] = 7;
            Model[2][2] = 2;
        }
        else if(k == 3) {
            Model[0][0] = 2;
            Model[0][1] = 9;
            Model[0][2] = 4;

            Model[1][0] = 7;
            Model[1][1] = 5;
            Model[1][2] = 3;

            Model[2][0] = 6;
            Model[2][1] = 1;
            Model[2][2] = 8;
        }
        else if(k == 4) {
            Model[0][0] = 2;
            Model[0][1] = 7;
            Model[0][2] = 6;

            Model[1][0] = 9;
            Model[1][1] = 5;
            Model[1][2] = 1;

            Model[2][0] = 4;
            Model[2][1] = 3;
            Model[2][2] = 8;
        }
        else if(k == 5) {
            Model[0][0] = 6;
            Model[0][1] = 1;
            Model[0][2] = 8;

            Model[1][0] = 7;
            Model[1][1] = 5;
            Model[1][2] = 3;

            Model[2][0] = 2;
            Model[2][1] = 9;
            Model[2][2] = 4;
        }
        else if(k == 6) {
            Model[0][0] = 6;
            Model[0][1] = 7;
            Model[0][2] = 2;

            Model[1][0] = 1;
            Model[1][1] = 5;
            Model[1][2] = 9;

            Model[2][0] = 8;
            Model[2][1] = 3;
            Model[2][2] = 4;
        }
        else if(k == 7) {
            Model[0][0] = 4;
            Model[0][1] = 3;
            Model[0][2] = 8;

            Model[1][0] = 9;
            Model[1][1] = 5;
            Model[1][2] = 1;

            Model[2][0] = 2;
            Model[2][1] = 7;
            Model[2][2] = 6;
        }
        aux = 0;
        for(unsigned int i = 0; i < 3; i++) {
            for(unsigned int j = 0; j < 3; j++) {
                if(S[i][j] != Model[i][j]) {
                    aux += abs(Model[i][j] - S[i][j]);
                    if(aux > cost) {
                        i = 3;
                        break;
                    }
                }
            }
        }
        if(aux < cost) cost = aux;
    }

    return cost;
}
