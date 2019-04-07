#include <bits/stdc++.h>
// WA
using namespace std;
#define MAX 10000
bool A[MAX][MAX];

void iniciarMatrix(int);
void display(int);
string getOwnWay(int, string, int, int);

int main() {
    short t;
    cin >> t;
    string path;
    int n;
    char dir;
    long fila, columna;

    for (short i = 1; i <= t; i++) {
        cin >> n;
        iniciarMatrix(n);
        fila = 0, columna = 0;
        cin.get(dir);
        A[0][0] = true;
        for (long j = 0; j < 2*n-1; j++) {
            cin.get(dir);
            if(dir == 'S') fila++;
            else columna++;
            A[fila][columna] = true;
        }
        //display(n);
        string ans = "";
        cout << "Case #" << i << ": " << getOwnWay(n, ans, 0, 0) << endl;
    }
    return 0;
}

void iniciarMatrix(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) A[i][j] = false;
}

void display(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

string getOwnWay(int n, string ans, int i, int j) {
    if(i == n-1 && j == n-1) return ans;

    if(A[i][j]) {
        if(j+1 < n && !A[i][j+1]) { // puedo moverme a E
            ans += "E";
            return getOwnWay(n, ans, i, j+1);
        }
        else if(i+1 < n && !A[i+1][j]) { // moverse hacia abajo
            ans += "S";
            return getOwnWay(n, ans, i+1, j);
        }
    }
    else {
        if(j+1 < n) {
            ans += "E";
            return getOwnWay(n, ans, i, j+1);
        }
        else if(i+1 < n) {
            ans += "S";
            return getOwnWay(n, ans, i+1, j);
        }
    }
    return "";
}
