#include <bits/stdc++.h>
// For test 1, passed
// Test 2 -> TLE
// Implementación por fuerza bruta
using namespace std;
typedef long long int lli;

void foregoneSolution(lli, int);
bool noFour(string);

int main() {
    lli n;
    int t;
    // Número de casos
    cin >> t;
    for (short i = 1; i <= t; i++) {
        cin >> n;
        foregoneSolution(n, i);
    }
    return 0;
}

void foregoneSolution(lli n, int caseNum) {
    for (lli i = 0, j = n; i <= n/2; i++, j--) {
        if(noFour(to_string(i)) && noFour(to_string(j))) {
            cout << "Case #" << caseNum << ": " << i << " " << j << endl;
            break;
        }
    }
}

bool noFour(string num) {
    bool ans = true;
    int len = num.size();
    int middle = len / 2;
    for (int i = 0, j = len-1; i <= middle; i++, j--) {
        if(num[i] == '4' || num[j] == '4') {
            ans = false;
            break;
        }
    }
    return ans;
}
