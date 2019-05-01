#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Buenas-Series#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, aux, cont = 0;
    cin >> n >> k;
    stack<int> pila;
    for(int i = n-1; i >= 0; i--) {
        cin >> aux;
        pila.push(aux);
    }

    while(n--) {
        if(k - pila.top() >= 0) {
            k -= pila.top();
            pila.pop();
            cont++;
        }
        else break;
    }
    cout << cont << endl;
    return 0;
}
