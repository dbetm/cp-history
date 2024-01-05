#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Alcoholic-Pilots#problems
using namespace std;

void procesar(int64_t, int64_t, int64_t, int64_t, int64_t);
int64_t gcd(int64_t a, int64_t b);

int main() {
    int64_t v1, d1, v2, d2;
    int64_t i = 1;
    while (true) {
        cin >> v1 >> d1 >> v2 >> d2;
        if(v1 == 0 && d1 == 0 && v2 == 0 && d2 == 0) break;
        procesar(v1, d1, v2, d2, i);
        i++;
    }
    cout << endl;
    return 0;
}

void procesar(int64_t v1, int64_t d1, int64_t v2, int64_t d2, int64_t i) {
    // times
    if(((double)d1 / (double)v1) > ((double)d2 / (double)v2)) {
        cout << "Case #" << i << ": No beer for the captain." << endl;
    }
    else { // The captain won the race or
        cout << "Case #" << i << ": You owe me a beer!" << endl;
    }
    int64_t a = (v2*d1) + (v1*d2);
    int64_t b = 2 * (v1*v2);
    int64_t comunDiv = gcd(a, b);
    if(a % b == 0) cout << "Avg. arrival time: " << a/comunDiv << endl;
    else {
        a /= comunDiv;
        b /= comunDiv;
        cout << "Avg. arrival time: " << a << "/" << b << endl;
    }
}

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a % b) : a;
}
