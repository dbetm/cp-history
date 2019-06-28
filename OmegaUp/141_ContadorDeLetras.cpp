#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;

int main() {
    char c;
    int A = 0, E = 0, I = 0, O = 0, U = 0, a = 0, e = 0, i = 0, o = 0, u = 0, espacios = 0, numeros = 0;
    string texto;
    getline(cin, texto);
    for (int i = 0; i < texto.size(); i++) {
        c = texto[i];
        switch (c) {
            case 'A':
                A++;
                break;
            case 'E':
                E++;
                break;
            case 'I':
                I++;
                break;
            case 'O':
                O++;
                break;
            case 'U':
                U++;
                break;
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            default:
                if((int)c == 32) espacios++;
                else if(c >= '0' && c <= '9') numeros++;
        }
    }

    cout << "A: " << A << endl;
    cout << "E: " << E << endl;
    cout << "I: " << I << endl;
    cout << "O: " << O << endl;
    cout << "U: " << U << endl;
    cout << "a: " << a << endl;
    cout << "e: " << e << endl;
    cout << "i: " << i << endl;
    cout << "o: " << o << endl;
    cout << "u: " << u << endl;
    cout << "numeros: " << numeros << endl;
    cout << "espacios: " << espacios << endl;

    return 0;
}
