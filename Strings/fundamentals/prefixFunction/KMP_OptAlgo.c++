#include <bits/stdc++.h>
// Compejidad
// Tiempo: O(n+m)
// Memoria: O(n)
using namespace std;

void kmp(string &t, string &s, vector<int> &ocurrencias);
vector<int> getLPS(string &s);

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
    vector<int> lps = getLPS(s);

    cout << "Longest Prefix Size" << endl;
    for (size_t i = 0; i < lps.size(); i++) {
        cout << lps[i] << ", ";
    }
    cout << endl;
    cout << setfill('-') << setw(20) << "-" << endl;

    int n = (int)s.size();
    int m = (int)t.size();

    int i = 0, j = 0;
    while(i < m) {
        if(j == n) {
            ocurrencias.push_back(i-n);
            j = lps[j-1];
        }
        else if(t[i] == s[j]) {
            i++;
            j++;
        }
        else {
            if(j > 0) j = lps[j-1];
            else i++;
        }
    }
    if(j == n) ocurrencias.push_back(i-n);
}

vector<int> getLPS(string &s) {
    int n = (int)s.size();
    vector<int> lps(n);

    for (int i = 1; i < n; i++) {
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j]) j = lps[j-1];
        if(s[j] == s[i]) j++;
        lps[i] = j;
    }

    return lps;
}
