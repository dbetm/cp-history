#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Formula-Recursiva-Cuatro#problems
using namespace std;

int64_t a[41] = {0};

int64_t fn(int64_t n) {
    if(n <= 3) return 1;
    else {
        if(a[n] == 0) {
            return a[n] = fn(n-1) + fn(n-2) + fn(n-3);
        }
        else return a[n];
    }
}

int main() {
    int64_t n;
    cin >> n;
    cout << fn(n) << endl;
    return 0;
}
