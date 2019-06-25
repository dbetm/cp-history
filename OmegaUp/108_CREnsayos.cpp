#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/CR-Ensayos#problems
using namespace std;

int main() {
    string texto;
    bool despuesPunto = false;
    bool inicioOracion = true;
    bool despuesSigno = false;
    getline(cin, texto);
    for (unsigned int i = 0; i < texto.size(); i++) {
        if(despuesPunto && texto[i] != ' ') {
            texto[i] = toupper(texto[i]);
            despuesPunto = false;
        }
        else if(despuesSigno && texto[i] != ' ') {
            texto[i] = toupper(texto[i]);
            despuesSigno = false;
        }
        else if(inicioOracion && texto[i] != ' ') {
            texto[i] = toupper(texto[i]);
            inicioOracion = false;
        }
        else if(texto[i] == '.') {
            despuesPunto = true;
        }
        else if(texto[i] == '!' || texto[i] == '?') {
            despuesSigno = true;
        }
        else {
            texto[i] = tolower(texto[i]);
        }
    }
    cout << texto << endl;
    return 0;
}
