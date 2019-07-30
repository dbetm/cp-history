#include <bits/stdc++.h>

using namespace std;

int64_t factorial(int n) {
    int64_t res = 1;
    for (size_t i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << factorial(n) << endl;
    }
    return 0;
}
