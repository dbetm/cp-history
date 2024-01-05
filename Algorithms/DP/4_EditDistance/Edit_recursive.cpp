#include <bits/stdc++.h>
// Source: GFG
// Time Complexity: 0(3^m)
using namespace std;

int min(int x, int y, int z) {
    return min(x, min(y, z));
}

int getMinDistance(string s1, string s2, int m, int n) {
    if(m == 0 || n == 0) return m + n;

    // Hay dos casos:
    // 1) Los últimos carácteres coinciden, entonces no hay que hacer nada
    if(s1[m-1] == s2[n-1]) return getMinDistance(s1, s2, m-1, n-1);
    // 2) Hacer alguna de las 3 operaciones para hacer que coincidan
    return 1 + min(getMinDistance(s1, s2, m, n-1), // inserción
        getMinDistance(s1, s2, m-1, n-1),          // reemplazo
        getMinDistance(s1, s2, m-1, n));           // borrar
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Min distance edit is: " << getMinDistance(s1, s2, s1.size(), s2. size()) << endl;
    return 0;
}
