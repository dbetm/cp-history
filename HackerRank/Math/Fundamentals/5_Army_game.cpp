#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    int suma = (m / 2) + (m % 2);
    int ans = suma * ceil((double)n / 2);
    cout << ans << endl;
    return 0;
}
