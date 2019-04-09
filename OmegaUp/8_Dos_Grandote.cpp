#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/pow-2#problems
using namespace std;

int main() {
    int n;
    cin >> n;
    int64_t res = 1;

    cout << (res << (n+1)) - 1 << endl;

    return 0;
}
