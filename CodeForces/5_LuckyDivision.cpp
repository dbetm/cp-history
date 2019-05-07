#include <bits/stdc++.h>
// https://codeforces.com/contest/122/problem/A
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[] = {4, 7, 47, 74, 44, 77, 444, 447, 474, 477, 777, 744, 747, 774};
    int tam = sizeof(a) / sizeof(int);
    bool ans = false;
    for (int i = 0; i < tam; i++) {
        if(n % a[i] == 0 || a[i] == n) {
            ans = true;
            break;
        }
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
