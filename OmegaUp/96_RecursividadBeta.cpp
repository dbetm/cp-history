#include <bits/stdc++.h>
// Parcialmente incorrecta
using namespace std;

typedef long int li;

li datos[1000000];
int pos = 0;

li fn(li n) {
    if(n <= 15) return datos[pos++] = 4*n;
    return datos[pos++] = (fn(n-10) * 5);
}

int main() {
    li n;
    cin >> n;
    fn(n);
    for (li i = 0; i < pos; i++) {
        cout << datos[i] << endl;
    }
    return 0;
}
