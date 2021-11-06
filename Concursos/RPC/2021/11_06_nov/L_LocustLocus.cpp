#include <bits/stdc++.h>

using namespace std;

long greatestCommonDivisor(long a, long b) {
    return b ? greatestCommonDivisor(b, a % b) : a;
}


long lcm(long a, long b) {
    return (a * b) / greatestCommonDivisor(a, b);
}

int computeNextYear(int y, int c1, int c2) {
    int leastCommonMultiple = (int)lcm(c1, c2);

    return y + leastCommonMultiple;
}

int main() {
    int k, y, c1, c2;
    cin >> k;
    int ans = -1;

    while (k--) {
        cin >> y >> c1 >> c2;
        auto nextYear = computeNextYear(y, c1, c2);
        if(ans != -1 and nextYear >= 2022) {
            ans = min(ans, nextYear);
        }
        else if (nextYear >= 2022) {
            ans = nextYear;
        }
    }

    cout << ans << endl;

    return 0;
}
