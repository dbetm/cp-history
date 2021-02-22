#include <bits/stdc++.h>
// Programa para imprimir todas las subsecuencias posibles en una cadena
/* Ejemplo: abc (2^3 posibles)
abc
ab
ac
bc
a
b
c
{}
*/
using namespace std;

void printAllSubsequences(string str, string output);

int main() {
    string str, output = "";
    cin >> str;

    printAllSubsequences(str, output);

    return 0;
}

void printAllSubsequences(string str, string output) {
    if(str.size() == 0) {
        cout << output << endl;
        return;
    }

    // Hay dos casos:
    // Incluir el caracter
    printAllSubsequences(str.substr(1), output + str[0]);
    // Excluir un caracter
    printAllSubsequences(str.substr(1), output);
}
