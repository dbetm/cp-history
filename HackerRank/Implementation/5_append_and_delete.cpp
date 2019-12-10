#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/append-and-delete/problem
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
// Se busca convertir s en t, usando k operaciones.
int main(int argc, char* argv[]) {
    string s, t;
    int k, cont = 0, aux, aux2, delta, delta2;
    unsigned int i;

    cin >> s;
    cin >> t;
    cin >> k;

    // Aux es el tamaño de la cadena source (s)
    aux = s.size();
    // aux2 es el tamaño de la cadena target (t)
    aux2 = t.size();

    for (i = 0; i < s.size() || i < t.size(); i++) {
        if(s[i] == t[i]) cont++;
        else break;
    }
    //watch(cont)

    if(t.size() == s.size() && (int)s.size() == cont) {
        if(k > 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        // delta es la diferencia entre la cadena s y el tamaño del
        // prefijo común de las 2 cadenas.
        delta = aux - cont;
        //watch(delta)
        delta2 = aux2 - cont;
        int res1 = k - (delta + delta2);
        int res2 = k - (aux + aux2);
        if(aux >= aux2) {
            if(res1 >= 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else {
            if(res2 >= 0 || (k >= (aux2 - aux) && res1 % 2 == 0))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
