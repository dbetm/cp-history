#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int EmoogleBalance;
    int aux;

    for(int i = 0; i < 75; i++) {
        cin >> N;
        EmoogleBalance = 0;
        for(int j = 0; j < N; j++) {
            cin >> aux;
            if(aux == 0) EmoogleBalance--;
            else EmoogleBalance++;
        }
        if(N == 0) break;
        cout << "Case " << i+1 << ": " << EmoogleBalance << "\n";
    }

    return 0;
}
