#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int cont = 0;
    string texto;
    bool espacio = true;
    getline(cin, texto);

    for (size_t i = 0; i < texto.size(); i++) {
        if(espacio && (texto[i] == 'h' || texto[i] == 'H')) {
            espacio = false;
            cont++;
        }
        else if((int)texto[i] == 32 || ((texto[i] < 'a' || texto[i] > 'z') && (texto[i] < 'A' || texto[i] > 'Z'))) espacio = true;
    }

    cout << cont << " haches" << endl;

    return 0;
}
