#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/A-jugar-2048#problems
using namespace std;

stack<int> stc;

void jugar(int bloque);

int main() {
    int n, bloque;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> bloque;
        jugar(bloque);
    }
    unsigned int tam = stc.size();
    cout << tam << endl;
    for (unsigned int i = 0; i < tam; i++) {
        cout << stc.top() << endl;
        stc.pop();
    }
    return 0;
}

void jugar(int bloque) {
    if(stc.empty()) {
        stc.push(bloque);
    }
    else {
        int tos = stc.top();
        if(bloque == tos) {
            stc.pop();
            int x = 2*bloque;
            jugar(x);
        }
        else stc.push(bloque);
    }
}
