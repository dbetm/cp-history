#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/gray#problems
using namespace std;

int main() {
    unsigned long long n, m;
    cin >> n;
    m = n >> 1;
    cout << (n^m) << endl;
    return 0;
}
