#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/CR-File-downloading#problems
using namespace std;

int main(int argc, char const *argv[]) {
    queue<string> fotos;
    string nombreFoto;
    char request;

    while(cin >> request) {
        if(request == 'D') {
            cin >> nombreFoto;
            fotos.push(nombreFoto);
            cout << "ok" << endl;
        }
        else if(request == 'T') {
            nombreFoto = fotos.front();
            fotos.pop();
            cout << "descargada " << nombreFoto << endl;
        }
        else if(request == 'C') {
            cout << "Faltan " << fotos.size() << " descarga(s)" << endl;
        }
        else if(request == 'X') {
            cout << fotos.size() << " descarga(s) abortadas" << endl;
        }
    }

    return 0;
}
