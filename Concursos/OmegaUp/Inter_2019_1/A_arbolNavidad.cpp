#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Arbol-de-navidad-estrellado#problems
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int tam = 2*n+1;
    int tam2 = n+1;
    int ele = -1;

    for (int i = 0; i < tam2; i++) {
        int espacios = n-i;
        ele += 2;
        int aux = ele;
        for (int j = 0; j < tam; j++) {
            if(espacios > 0) {
                cout << " ";
                espacios--;
            }
            else if(aux > 0) {
                if(ele == 1) cout << "*";
                else cout << "o";
                aux--;
            }
            else {
                break;
            }
        }
        cout << "\n";
    }

    return 0;
}
