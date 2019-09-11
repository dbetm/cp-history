#include <bits/stdc++.h>

using namespace std;

int main() {
    string oracion;
    bool diccionario[26] = {false};
    getline(cin, oracion);
    for (size_t i = 0; i < oracion.size(); i++) {
        char letra = tolower(oracion[i]);
        if(letra >= 'a' && letra <= 'z') {
            diccionario[(int)(letra)-97] = true;
        }
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if(!diccionario[i]) {
            flag = false;
            break;
        }
    }

    cout << ((flag) ? "pangram" : "not pangram");

    return 0;
}
