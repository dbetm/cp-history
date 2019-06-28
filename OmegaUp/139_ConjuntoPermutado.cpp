#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Conjunto-Permutado#problems
using namespace std;

int A[1001];

int main() {
    int n, num;
    cin >> n;
    bool esPermutado = true;

    for (int i = 0; i < n; i++) {
        cin >> num;
        A[num]++;
    }
    int i;
    for (i = 0; i < n; i++) {
        cin >> num;
        if(A[num] == 0) {
            esPermutado = false;
            break;
        }
    }
    for (int j = i+1; j < n; j++) cin >> num;

    if(esPermutado) cout << "SI" << endl;
    else cout << "NO" << endl;

    return 0;
}
