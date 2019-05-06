#include <bits/stdc++.h>

using namespace std;

int64_t countMinutes(int64_t n, int64_t m) {
    int64_t minutes;
    int64_t greatestCommonDivisor = __gcd(n, m);
    minutes = (n * m) / (greatestCommonDivisor * greatestCommonDivisor);
    return minutes;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int64_t n, m;
    cin >> n >> m;
    cout << countMinutes(n, m) << endl;
	return 0;
}
