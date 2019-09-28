#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    unsigned long int a, b;
    char letra;
    cin >> a >> b;
    cin.get();
    while (cin.get(letra) && (int)letra != 10) {
        cout << (char)(((a * ((int)(letra) - 65) + b) % 26) + 65);
    }
    cout << "\n";

    return 0;
}
