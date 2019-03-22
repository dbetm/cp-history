#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int f, c;
    cin >> f >> c;
    int A[f][c];

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int i = f-1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if(j != c) cout << A[i][j] << " ";
            else cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}
