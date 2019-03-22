#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/ABCdario#problems
using namespace std;

int main(int argc, char const *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string abcdario;
    // N es el número de compañeros a los que le pregunta
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> abcdario;
        set<char> letras;
        for (unsigned int j = 0; j < abcdario.size(); j++) letras.insert(abcdario[j]);
        if(letras.size() == 26) cout << "PERFECT\n";
        else cout << "NO WAY\n";
    }
    return 0;
}
