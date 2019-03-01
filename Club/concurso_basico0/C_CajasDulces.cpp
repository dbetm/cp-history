#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    int max = 0;
    for (int i = 0; i <= n - k; i++) {
        int suma = 0;
        for (int j = i; j < i + k; j++) suma += A[j];
        if(suma > max) max = suma;
    }
    cout << max << endl;
    return 0;
}
