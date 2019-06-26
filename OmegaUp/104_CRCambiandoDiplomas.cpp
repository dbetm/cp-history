#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/CR-Cambiando-diplomas#problems
using namespace std;

void reemplazar(string &texto, string match, string nuevo) {
    int n = match.size();
    int index = 0;
    while(true) {
        index = texto.find(match, index);
        if(index == (int)string::npos) break;
        texto.replace(index, n, nuevo);
        index += n;
    }
}

int main() {
    int n;
    string n1, n2, texto;
    cin >> n;
    vector <pair<string, string>> nombres;
    for (int i = 0; i < n; i++) {
        cin >> n1 >> n2;
        nombres.push_back(make_pair(n1, n2));
    }
    cin.get();
    getline(cin, texto);
    for (int i = 0; i < n; i++) {
        reemplazar(texto, nombres[i].first, nombres[i].second);
    }
    /*
    while(n--) {

    }*/
    cout << texto << endl;
    return 0;
}
