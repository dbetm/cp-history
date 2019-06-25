#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/CR-A-contar-20#problems
using namespace std;

int main() {
    char c;
    int suma = 0;
    while(cin >> c) {
        if(c >= '0' && c <= '9') suma += (int)c - 48;
    }

    cout << suma << endl;
    return 0;
}
