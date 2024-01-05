#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int ans;
    cout << "Escribe n: ";
    cin >> n;
    int A[n+1];
    if(n > 2) {
        A[0] = 1;
        A[1] = 1;
        for (int i = 2; i <= n; i++) {
            A[i] = A[i-1] * i;
        }
        ans = A[n];
    }
    else ans = 1;

    cout << ans << endl;
    return 0;
}
