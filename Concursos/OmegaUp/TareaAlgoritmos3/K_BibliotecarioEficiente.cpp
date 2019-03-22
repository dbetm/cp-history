#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cin.get();
    vector<string> disponibilidad(n);
    vector<string> nombres(n);
    string nombre;

    for (int i = 0; i < n; i++) {
        getline(cin, nombres[i]);
        getline(cin, disponibilidad[i]);
    }

    getline(cin, nombre);

    for (int i = 0; i < n; i++) {
        if(nombres[i] == nombre) {
            cout << disponibilidad[i] << endl;
            break;
        }
    }

    return 0;
}
