#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, t, a, b;
    cin >> n;
    int A[n], suma[n] = {};
    cin >> A[0];
    suma[0] = A[0];

    for (int i = 1; i < n; i++) {
        cin >> A[i];
        suma[i] = A[i] + suma[i-1];
        cout << suma[i] << endl;
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << suma[b] - suma[a-1] << endl;
    }

    return 0;
}
