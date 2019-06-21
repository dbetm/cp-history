#include <bits/stdc++.h>
using namespace std;
// https://omegaup.com/arena/problem/Formula-Recursiva-Uno#problems
int64_t fn(int n) {
    if(n <= 5) return 1;
    else return fn(n - 2) * 5;
}

int main() {
    int n;
    cin >> n;
    cout << fn(n) << endl;
    return 0;
}
