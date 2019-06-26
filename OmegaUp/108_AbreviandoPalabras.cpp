#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Abreviando-palabras#problems
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string word;
    unsigned int tam;

    cin >> word;
    tam = word.size();
    if(tam > 10) {
        cout << word[0] << tam-2 << word[tam-1] << endl;
    }
    else cout << word << endl;

    return 0;
}
