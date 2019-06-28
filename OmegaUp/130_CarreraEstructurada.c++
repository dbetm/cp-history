#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Carrera-estructurada#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int id, cat;
    double tiempo;
    string nombre;
    cin >> n;
    vector<pair<double, pair<int, string>>> cat1;
    vector<pair<double, pair<int, string>>> cat2;

    for (int i = 0; i < n; i++) {
        cin >> id;
        cin.get();
        getline(cin, nombre);
        cin >> tiempo;
        cin >> cat;
        pair<int, string> persona;
        persona.first = id;
        persona.second = nombre;
        pair<double, pair<int, string>> estructura;
        estructura.first = tiempo;
        estructura.second = persona;
        if(cat == 1) cat1.push_back(estructura);
        else cat2.push_back(estructura);
    }
    sort(cat1.begin(), cat1.end());
    sort(cat2.begin(), cat2.end());

    for (int i = 0; i < 3; i++) {
        cout << cat1[i].second.first << " " << cat1[i].second.second << endl;
    }
    if(!cat2.empty())
        for (int i = 0; i < 3; i++) {
            cout << cat2[i].second.first << " " << cat2[i].second.second << endl;
        }

    return 0;
}
