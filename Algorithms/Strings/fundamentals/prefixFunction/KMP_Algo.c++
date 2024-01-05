#include <bits/stdc++.h>

using namespace std;

void kmp(string &t, string &s, vector<int> &ocurrencias);

int main() {
    string texto;
    string patron;
    cout << "Escribe el texto: " << endl;
    getline(cin, texto);
    cout << "Escribe el patrón a buscar" << endl;
    cin >> patron;

    vector<int> ocurrencias;
    kmp(texto, patron, ocurrencias);
    cout << "Hay ocurrencias en las posiciones: " << endl;
    int n = ocurrencias.size();
    for (int i = 0; i < n; i++) {
        cout << "i: " << ocurrencias[i] << endl;
    }
    return 0;
}

void kmp(string &t, string &s, vector<int> &ocurrencias) {
    string todo = s + "#" + t;
    int n = s.size();
    int mn = (int)todo.size();
    vector<int> pi(mn);

    for (int i = 1; i < mn; i++) {
        int j = pi[i-1];
        while(j > 0 && todo[i] != todo[j]) j = pi[j-1];
        if(todo[i] == todo[j]) j++;
        pi[i] = j;
        if(pi[i] == n) {
            ocurrencias.push_back(i-2*n);
        }
    }
}
