#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/SSS#problems
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int64_t suma;
    int64_t sumaTotal = 0;
    cin >> n;
    int64_t sumas[n+1] = {};
    sumas[1] = 1;
    sumaTotal = 1;

    for (int i = 2; i <= n; i++) {
        suma = (i * (i + 1)) / 2;
        sumas[i] = suma + sumas[i-1];
        sumaTotal += sumas[i];
    }

    cout << sumaTotal << endl;

    return 0;
}
