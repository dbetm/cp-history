#include <bits/stdc++.h>
// Equipo Pistas de NULL
// Por David
// Aceptado
using namespace std;

int main() {
    string s1, s2;
    int k;
    cin >> k;
    cin >> s1;
    cin >> s2;
    int c = 0;

    for (unsigned int i = 0; i < s1.size(); i++) if(s1[i] == s2[i]) c++;
    cout << s1.size() - abs(k-c) << endl;
    return 0;
}
